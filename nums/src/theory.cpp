#include "theory.h"
#include "primes.h"
#include <vector>
#include <utility>
#include <cmath>
#include <cstdint>

using namespace std;

vector<int> continuing_fraction_sqrt(int s) {
  int a = isqrt(s);
  int m = 0;
  int d = 1;
  vector<int> ret = {a};
  if (a*a == s) {
    return ret;
  }
  while (a != *ret.begin() * 2) {
    m = d*a - m;
    d = (s - m*m)/d;
    a = (*ret.begin() + m) / d;
    ret.push_back(a);
  }
  return move(ret);
}

void extended_gcd_update(int quotient, int *v, int *old_v) {
  int tmp = *v;
  *v = *old_v - quotient * *v;
  *old_v = tmp;
}

pair<int, int> extended_gcd(int a, int b) {
  int vs[] = {0, 1, b};
  int old_vs[] = {1, 0, a};
  while (vs[2] != 0) {
    int quotient = old_vs[2] / vs[2];
    for (int i = 0; i < 3; i++) {
      extended_gcd_update(quotient, &(vs[i]), &(old_vs[i]));
    }
  }
  return move(make_pair(old_vs[0], old_vs[1]));
}

int gcd(int a, int b) {
  while (a * b != 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a+b;
}

long long totient(long long n) {
  long long r = n;
  for (const auto &p : unique_prime_factors(n)) {
    if (p == r) {
      r--;
    } else {
      r /= p;
      r *= p - 1;
    }
  }
  return r;
}

bool is_perm(int a, int b) {
  uint8_t hist[10] = {0};
  while (a!= 0 && b!= 0) {
    hist[a%10]++;
    hist[b%10]--;
    a/=10;
    b/=10;
  }
  if (a != 0 || b != 0) {
    return false;
  }
  for (int i = 0; i < 10; i++) {
    if (hist[i] != 0) {
      return false;
    }
  }
  return true;
}

bool is_square(long s) {
  int x = isqrt(s);
  return x*x == s;
}

unsigned long long choose(int n, int k) {
  if (k > n) {
    return 0;
  }
  k = min(k, n-k);
  unsigned long long *table = new unsigned long long[n+1](); //alloc and set to 0
  for (int i = 0; i <= n; i++) {
    table[i] = 0;
  }
  table[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int r = i; r > 0; r--) {
      table[r] += table[r-1];
    }
  }
  auto ret = table[k];
  delete[] table;
  return ret;
}

int length(unsigned long long v, int b) {
  if (v == 0) {return 1;}
  return static_cast<int>(log(v) / log(b)) + 1;
}

long long concatenate(int n1, int n2, int b) {
  return static_cast<long long>(pow(b, length(n2, b))) * n1 + n2;
}

int figurate_number(int s, int n) {
  return n * ((s-2)*n + 4 - s) / 2;
}

int isqrt(unsigned long long v) {
  return static_cast<int>(sqrt(v));
}

