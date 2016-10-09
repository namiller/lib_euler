#include "nums/primes.h"
#include "gtest/gtest.h"
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

TEST(PrimesToN, size) {
  ASSERT_EQ(4, primes_to_n(10).size());
  ASSERT_EQ(0, primes_to_n(1).size());
  ASSERT_EQ(1, primes_to_n(2).size());
  ASSERT_EQ(1000, primes_to_n(7919).size());
  ASSERT_EQ(1000, primes_to_n(7920).size());
}

TEST(PrimesToN, primality) {
  for (const auto & p : primes_to_n(1000)) {
    ASSERT_EQ(true, is_prime(p));
  }
}

TEST(NPrimes, size) {
  for (int i = 0; i < 500; i++) {
    ASSERT_EQ(i, n_primes(i).size());
  }
}

TEST(NPrimes, composition) {
  for (int i = 500; i < 1000; i+=100) {
    vector<int> l1 = primes_to_n(i);
    ASSERT_EQ(l1, n_primes(l1.size()));
  }
}

TEST(IsPrime, ten_digit_primes) {
  ASSERT_EQ(true, is_prime(5915587277LL));
  ASSERT_EQ(true, is_prime(1500450271LL));
  ASSERT_EQ(true, is_prime(3267000013LL));
  ASSERT_EQ(true, is_prime(5754853343LL));
  ASSERT_EQ(true, is_prime(4093082899LL));
  ASSERT_EQ(true, is_prime(9576890767LL));
  ASSERT_EQ(true, is_prime(3628273133LL));
  ASSERT_EQ(true, is_prime(2860486313LL));
  ASSERT_EQ(true, is_prime(5463458053LL));
  ASSERT_EQ(true, is_prime(3367900313LL));
}

TEST(IsPrime, almost_prime) {
  ASSERT_EQ(false, is_prime(21727LL*23767LL));
  ASSERT_EQ(false, is_prime(33713LL*83873LL));
  ASSERT_EQ(false, is_prime(34591LL*84731LL));
  ASSERT_EQ(false, is_prime(70001LL*4931LL));
  ASSERT_EQ(false, is_prime(85819LL*22229LL));
}
TEST(IsPrime, squares) {
  for (long long i = 0; i < 1000; i++) {
    ASSERT_EQ(false, is_prime(i*i));
  }
}

TEST(IsPrime, edge) {
  ASSERT_EQ(false, is_prime(1));
  ASSERT_EQ(false, is_prime(0));
  ASSERT_EQ(false, is_prime(-1));
  ASSERT_EQ(false, is_prime(-2));
  ASSERT_EQ(true, is_prime(2));
}

TEST(UniquePrimeFactors, simple) {
  ASSERT_EQ(2, unique_prime_factors(12).size());
}

TEST(UniquePrimeFactors, primes) {
  for (const auto & p : n_primes(100)) {
    vector<int> factors = unique_prime_factors(p);
    ASSERT_EQ(1, factors.size());
    ASSERT_EQ(p, factors[0]);
  }
}

TEST(UniquePrimeFactors, squares) {
  for (int i = 1; i < 100; i++) {
    ASSERT_EQ(unique_prime_factors(i), unique_prime_factors(i*i));
  }
}

TEST(UniquePrimeFactors, repeated) {
  ASSERT_EQ(vector<int>({2,3}), unique_prime_factors(2*2*3));
  ASSERT_EQ(vector<int>({2,5}), unique_prime_factors(1000));
  ASSERT_EQ(vector<int>({2,3,5,7}), unique_prime_factors(2*2*2*3*5*7*7*7));
  ASSERT_EQ(vector<int>({5,7,11}), unique_prime_factors(5*7*11*11));
}

TEST(UniquePrimeFactors, non_repeated) {
  ASSERT_EQ(vector<int>({2,3}), unique_prime_factors(2*3));
  ASSERT_EQ(vector<int>({2,5}), unique_prime_factors(10));
  ASSERT_EQ(vector<int>({2,3,5,7}), unique_prime_factors(2*3*5*7));
  ASSERT_EQ(vector<int>({5,7,11}), unique_prime_factors(5*7*11));
}

TEST(UniquePrimeFactors, uniqueness) {
  for (int i = 1; i < 10000; i++) {
    vector<int> factors = unique_prime_factors(i);
    set<int> s;
    for (const auto &f : factors) {
      s.insert(f);
    }
    ASSERT_EQ(s.size(), factors.size());
  }
}

TEST(PrimeFactors, recomposition) {
  for (int i = 1; i < 100000; i++) {
    auto fs = prime_factors(i);
    int prod = 1;
    for (const auto &f : fs) {
      prod *= f;
    }
    ASSERT_EQ(prod, i);
  }
}

TEST(PrimeFactors, squares) {
  for (int i = 1; i < 1000; i++) {
    ASSERT_EQ(prime_factors(i).size() * 2, prime_factors(i*i).size());
  }
}

TEST(PrimeFactors, repeated) {
  ASSERT_EQ(vector<int>({2,2,3}), prime_factors(2*2*3));
  ASSERT_EQ(vector<int>({2,2,2,5,5,5}), prime_factors(1000));
  ASSERT_EQ(vector<int>({2,2,2,3,5,7,7,7}), prime_factors(2*2*2*3*5*7*7*7));
  ASSERT_EQ(vector<int>({5,7,11,11}), prime_factors(5*7*11*11));
}

TEST(PrimeFactors, non_repeated) {
  ASSERT_EQ(vector<int>({2,3}), prime_factors(2*3));
  ASSERT_EQ(vector<int>({2,5}), prime_factors(10));
  ASSERT_EQ(vector<int>({2,3,5,7}), prime_factors(2*3*5*7));
  ASSERT_EQ(vector<int>({5,7,11}), prime_factors(5*7*11));
}

TEST(ProbablyPrime, consistancy) {
  for (int i = 1; i < 100000; i++) {
    ASSERT_EQ(probably_prime(i), is_prime(i));
  }
}

TEST(ProbablyPrime, fuzz) {
  srand(123);
  for (int i = 0; i < 1000; i++) {
    auto r = rand();
    ASSERT_EQ(probably_prime(r), is_prime(r));
  }
}

TEST(ProbablyPrime, pseudo) {
  ASSERT_EQ(false, probably_prime(90751)); // 2
  ASSERT_EQ(false, probably_prime(97567)); // 3
  ASSERT_EQ(false, probably_prime(79381)); // 5
  ASSERT_EQ(false, probably_prime(25326001)); // 2, 3, 5
  ASSERT_EQ(false, probably_prime(3825123056546413051LL)); // 2,3,5,7,11,13,17,19,23
}

