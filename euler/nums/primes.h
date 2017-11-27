#ifndef PRIMES_H
#define PRIMES_H

#include <utility>
#include <vector>

// Generate the first n prime numbers
std::vector<int> n_primes(unsigned int n);

// Generate prime numbers up to (but not exceeding) n. If n is prime, it will be included.
std::vector<int> primes_to_n(int n);

// Determines if n is prime (returns true if it is)
bool is_prime(unsigned long long n);

// Miller Rabin primality testing (returns true if n is probably prime)
bool probably_prime(unsigned long long n);

// Returns the unique prime factors of n in increasing order (ie 12 -> 2,3)
template<typename Num>
std::vector<Num> unique_prime_factors(Num n) {
  std::vector<Num> factors;
  while (n % 2 == 0) {
    n /= 2;
    if (factors.size() == 0) {
      factors.push_back(2);
    }
  }
  for (Num f = 3; f*f <= n; f+= 2) {
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

// Returns the prime factors of n in non-decreasing order (ie 12 -> 2,2,3)
std::vector<int> prime_factors(int n);

// Returns an <p, e> pair for each prime factor of n where p is the prime factor and e is the cardinality (ie 12 -> <2,2>, <3,1>)
std::vector<std::pair<int, int> > prime_factor_powers(int n);

#endif //PRIMES_H
