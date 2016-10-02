#include "theory.h"
#include "primes.h"
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<int> continuing_fraction_sqrt(int s) {
  int a = static_cast<int>(sqrt(s));
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

void gcd_update(int quotient, int *v, int *old_v) {
  int tmp = *v;
  *v = *old_v - quotient * *v;
  *old_v = tmp;
}

//TODO: implement
pair<int, int> extended_gcd(int a, int b) {
  int vs[] = {0, 1, b};
  int old_vs[] = {1, 0, a};
  while (vs[2] != 0) {
    int quotient = old_vs[2] / vs[2];
    for (int i = 0; i++; i < 3) {
      gcd_update(quotient, &(vs[i]), &(old_vs[i]));
    }
  }
  return move(make_pair(vs[0], vs[1]));
}

//TODO: implement
int gcd(int a, int b) {
  return 1;
}

//TODO: implement
int totient(int n) {
  double r = n;
  for (const auto & p : unique_prime_factors(n)) {
    r *= 1.0 - 1.0 / p;
  }
  return static_cast<int>(r);
}

//TODO: implement
bool is_perm(int a, int b) {
  return false;
}

//TODO: implement
bool is_square(long s) {
  return false;
}

//TODO: implement
int choose(int n, int k) {
  return 0;
}

//TODO: implement
long concatenate(int n1, int n2, int b) {
  return 0;
}

//TODO: implement
int figurate_number(int s, int n) {
  return 0;
}
