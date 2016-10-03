#ifndef THEORY_H
#define THEORY_H

#include <utility>
#include <vector>

std::vector<int> continuing_fraction_sqrt(int s);

// TODO: maybe make this templated...
//big_int eval_continuing_fraction(vector<int> c);

// performs extended gcd on a and b returning the coefficients <s, t> such that as+bt =1. (for rel-prime a and b)
std::pair<int, int> extended_gcd(int a, int b);

// returns the greatest common divisor of a and b.
int gcd(int a, int b);

// returns euler's totient function of n.
long long totient(long long n);

// returns true iff a and be are composed of the same digits
bool is_perm(int a, int b);

// returns the modular exponentiation of b^e%m
// argument type must support %= by m, *= by itself, & by 1 (extract last bit), 
// >>= by 1, assignment and casting from 1.
template<typename num, typename t2, typename t3>
num mod_exp(num b, t2 e, t3 m) {
  auto res = static_cast<num>(1);
  auto partial = b;
  while (e) {
    if (e & 1) {
      res *= partial;
      res %= m;
    }   
    partial *= partial;
    partial %= m;
    e >>= 1;
  }
  return res;
}

// returns true iff the integral argument is a perfect square.
bool is_square(long s);

// returns n C k
unsigned long long choose(int n, int k);

// TODO: maybe shouldn't be an int...
// returns the integer concatenation of n1..n2 (in base b = 10 by default).
long long concatenate(int n1, int n2, int b = 10);

// returns the nth s-figurate number (ie s=3 returns the nth triangle number, 4-> squares, etc).
int figurate_number(int s, int n);

int isqrt(unsigned long long v);

// returns the length (number of digits) of the number v in base b (default 10)
int length(unsigned long long v, int b = 10);

#endif //THEORY_H
