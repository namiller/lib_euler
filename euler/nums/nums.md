#Number Theoretic Utils
The number theoretic utils are partitioned into prime number utilities, and higher level utilities.

##Primes
Basic utilities include generating lists of prime numbers,
```
vector<int> n_primes(int n);
vector<int> primes_to_n(int n);
```
checking primality either by checking all divisors
```
bool is_prime(long long n);
```
or by the Miller Rabin primality test (derandomized).
```
bool probably_prime(long long n);
```
Finally there are utilities for prime factoring numbers.
```
vector<int> prime_factors(int n);
vector<pair<int, int>> prime_factor_powers(int n);
```

##Higher Level Functions
This is a dumping ground for all number theoretic functions that need to be implemented. They include utilities to:

* Compute continuing fractions
* Compute extended gcd coefficients
* Compute gcd
* Euler's totient function
* Digital permutation checker
* Modular exponentiation
* Perfect square checking
* N choose K cardinality
* Integer concatenation (in arbitrary base)
* Integer square root
* Number of digits in (in arbitrary base)