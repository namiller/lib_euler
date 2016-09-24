#include "primes.h"
#include "theory.h" // for mod_exp
#include <vector>
#include <utility>

using namespace std;

vector<int> n_primes(int n) {
  if (n <= 0) {
    return vector<int>();
  } else if (n == 1) {
    return {2};
  }
  vector<int> primes = {2, 3};
  while (primes.size() < n) {
    for (int c = primes.back() + 2; ; c+=2) {
      bool works = true;
      for (const auto & p : primes) {
        if (c%p == 0) {
          works = false;
          break;
        }
      }
      if (works) {
        primes.push_back(c);
        break;
      }
    }
  }
  return primes;
}

vector<int> primes_to_n(int n) {
  if (n < 2) {
    return vector<int>();
  }
  vector<bool> seive(n+1, 0);
  seive[0] = seive[1] = true;
  seive[2] = false;
  vector<int> primes;
  for (int i = 0; i <= n; i++) {
    if (!seive[i]) {
      primes.push_back(i);
      for (int m = 2 * i; m <=n; m += i) {
        seive[m] = true;
      }
    }
  }
  return move(primes);
}

bool is_prime(long long n) {
  if (n<2) {
    return false;
  }
  if (n!=2 && n%2 == 0) {
    return false;
  }
  for (long f = 3; f*f <= n; f+=2) {
    if (n%f == 0) {
      return false;
    }
  }
  return true;
}

// TODO: implement Miller Rabin.
bool probably_prime(long long n) {
  const vector<int> as = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 27}; // derandomize.
  if (n == 2 || n == 3) {
    return true;
  } else if (n % 2 == 0 || n < 2) {
    return false;
  }
  // n is now > 3 and odd.
  long long d = n - 1;
  long s = 0;
  while (!(d & 1)) {
    d >>= 1;
    s++;
  }
  // n - 1 = 2^s*d
  for (const auto a : as) {
    bool witness = true;
    if (a > n-2) {
      break;
    }
    long long x = mod_exp((long long)a, d, n);
    if ( x == 1 || x == n-1) {
      continue;
    }
    for (int r = 1; r < s; r++) {
      x = mod_exp(x,2LL,n);
      if (x == 1) {
        return false;
      }
      if (x == n - 1) {
        witness = false;
        break;
      }
    }
    if (witness) {
      return false;
    }
  }
  return true;
}

vector<int> unique_prime_factors(int n) {
  vector<int> factors;
  while (n % 2 == 0) {
    n /= 2;
    if (factors.size() == 0) {
      factors.push_back(2);
    }
  }
  for (int f = 3; f*f <= n; f+= 2) {
    while (n % f == 0) {
      n /= f;
      if (factors.size() == 0 || factors.back() != f) {
        factors.push_back(f);
      }
    }
  }
  if (n != 1 && (factors.size() == 0 || factors.back() != n)) {
    factors.push_back(n);
  }
  return move(factors);
}

vector<int> prime_factors(int n) {
  vector<int> factors;
  while (n%2 == 0) {
    n /= 2;
    factors.push_back(2);
  }
  for (int f = 3; f*f <= n; f+=2) {
    while (n%f == 0) {
      n /= f;
      factors.push_back(f);
    }
  }
  if (n != 1) {
    factors.push_back(n);
  }
  return move(factors);
}
