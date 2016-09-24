#ifndef PRIMES_H
#define PRIMES_H

#include <utility>
#include <vector>

// Generate the first n prime numbers
std::vector<int> n_primes(int n);

// Generate prime numbers up to (but not exceeding) n. If n is prime, it will be included.
std::vector<int> primes_to_n(int n);

// Determines if n is prime (returns true if it is)
bool is_prime(long long n);

// Miller Rabin primality testing (returns true if n is probably prime)
bool probably_prime(long long n);

// Returns the unique prime factors of n in increasing order (ie 12 -> 2,3)
std::vector<int> unique_prime_factors(int n);

// Returns the prime factors of n in non-decreasing order (ie 12 -> 2,2,3)
std::vector<int> prime_factors(int n);

// Returns an <p, e> pair for each prime factor of n where p is the prime factor and e is the cardinality (ie 12 -> <2,2>, <3,1>)
std::vector<std::pair<int, int> > prime_factor_powers(int n);

#endif //PRIMES_H
