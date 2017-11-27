#include "euler/nums/primes.h"
#include "euler/nums/theory.h"

#include <vector>
#include <utility>

using namespace std;

vector<int> n_primes(unsigned int n) {
  if (n <= 0) {
    return vector<int>();
  } else if (n == 1) {
    return {2};
  }
  vector<int> primes = {2, 3};
	primes.reserve(n);
  while (primes.size() < n) {
    for (int c = primes.back() + 2; ; c+=2) {
      bool works = true;
      for (const auto & p : primes) {
        if (c%p == 0) {
          works = false;
          break;
        } 
				if (p*p > c) {
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
  return primes;
}

bool is_prime(unsigned long long n) {
  if (n<2) {
    return false;
  }
  if (n!=2 && n%2 == 0) {
    return false;
  }
  for (unsigned long long f = 3; f*f <= n; f+=2) {
    if (n%f == 0) {
      return false;
    }
  }
  return true;
}

bool probably_prime(unsigned long long n) {
  const vector<unsigned int> as = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; // derandomize.
  if (n == 2 || n == 3) {
    return true;
  } else if (n % 2 == 0 || n < 2) {
    return false;
  }
  // n is now > 3 and odd.
  unsigned long long d = n - 1;
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
    unsigned long long x = mod_exp((unsigned long long)a, d, n);
    if (x == 1 || x == n-1) {
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
  return factors;
}
