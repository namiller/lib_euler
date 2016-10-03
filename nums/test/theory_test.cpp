#include "../include/theory.h"
#include <gtest/gtest.h>
#include <vector>
#include <utility>

using namespace std;

TEST(ContinuingSqrt, square) {
  ASSERT_EQ(vector<int>({3}), continuing_fraction_sqrt(9));
}
TEST(ContinuingSqrt, unity) {
  ASSERT_EQ(vector<int>({1}), continuing_fraction_sqrt(1));
}
TEST(ContinuingSqrt, zero) {
  ASSERT_EQ(vector<int>({0}), continuing_fraction_sqrt(0));
}
TEST(ContinuingSqrt, unit_period) {
  ASSERT_EQ(vector<int>({1,2}), continuing_fraction_sqrt(2));
}
TEST(ContinuingSqrt, long_odd_period) {
  ASSERT_EQ(vector<int>({4,1,2,4,2,1,8}), continuing_fraction_sqrt(22));
}
TEST(ContinuingSqrt, even_period) {
  ASSERT_EQ(vector<int>({2,1,1,1,4}), continuing_fraction_sqrt(7));
}
TEST(ContinuingSqrt, short_even_period) {
  ASSERT_EQ(vector<int>({2,2,4}), continuing_fraction_sqrt(6));
}
TEST(ContinuingSqrt, size_long) {
  ASSERT_EQ(27, continuing_fraction_sqrt(211).size());
}
TEST(ContinuingSqrt, size_very_long) {
  ASSERT_EQ(1017, continuing_fraction_sqrt(162094).size());
}

TEST(GCD, dec_order) {
  ASSERT_EQ(8, gcd(32, 24));
}
TEST(GCD, inc_order) {
  ASSERT_EQ(8, gcd(24, 32));
}
TEST(GCD, prime_mult) {
  ASSERT_EQ(7, gcd(7, 14));
}
TEST(GCD, prime_mult_rev) {
  ASSERT_EQ(7, gcd(14, 7));
}

TEST(ExtendedGCD, no_repeat) {
  ASSERT_EQ(make_pair(1,-2), extended_gcd(5,2));
}
TEST(ExtendedGCD, no_repeat_rev) {
  ASSERT_EQ(make_pair(-2,1), extended_gcd(2,5));
}
TEST(ExtendedGCD, adjacent_nums) {
  ASSERT_EQ(make_pair(1,-1), extended_gcd(1234,1233));
}
TEST(ExtendedGCD, adjacent_nums_rev) {
  ASSERT_EQ(make_pair(-1,1), extended_gcd(1233,1234));
}
TEST(ExtendedGCD, non_rel_prime) {
  ASSERT_EQ(make_pair(-1,1), extended_gcd(24, 32));
}
TEST(ExtendedGCD, repeate) {
  ASSERT_EQ(make_pair(3, -2), extended_gcd(5, 7));
}
TEST(ExtendedGCD, repeate_rev) {
  ASSERT_EQ(make_pair(-2, 3), extended_gcd(7, 5));
}

TEST(ExtendedGCD_GCD, equivalence_check) {
  for (int a = 1; a < 1000; a++) {
    for (int b = 1; b < 1000; b++) {
      auto p = extended_gcd(a,b);
      ASSERT_EQ(gcd(a,b), p.first*a+p.second*b);
    }
  }
}

TEST(Totient, perfect) {
  ASSERT_EQ(8, totient(24));
}
TEST(Totient, square) {
  ASSERT_EQ(6, totient(9));
}
TEST(Totient, unit) {
  ASSERT_EQ(1, totient(1));
}
TEST(Totient, dual) {
  ASSERT_EQ(1, totient(2));
}
TEST(Totient, large) {
  ASSERT_EQ(54, totient(81));
}
TEST(Totient, small) {
  ASSERT_EQ(24, totient(90));
}
TEST(Totient, big_prime) {
  ASSERT_EQ(9007199254740880LL, totient(9007199254740881LL));
}
TEST(Totient, big_composite) {
  ASSERT_EQ(3543665657495040LL, totient(9007199254740880LL));
}

TEST(ModExp, no_mod) {
  ASSERT_EQ(5*5*5*5, mod_exp(5,4,10000));
  ASSERT_EQ(1234*1234, mod_exp(1234,2,100000000));
}
TEST(ModExp, zero_remainder) {
  ASSERT_EQ(0, mod_exp(10,12312, 1000));
}

TEST(IsSquare, zero) {
  ASSERT_EQ(true, is_square(0));
}
TEST(IsSquare, one) {
  ASSERT_EQ(true, is_square(1));
}
TEST(IsSquare, not_square) {
  ASSERT_EQ(false, is_square(2));
}
TEST(IsSquare, square) {
  ASSERT_EQ(true, is_square(4));
}
TEST(IsSquare, negative_non) {
  ASSERT_EQ(false, is_square(-2));
}
TEST(IsSquare, negative_sqr) {
  ASSERT_EQ(false, is_square(-4));
}

TEST(IntegerSquareRoot, zero) {
  ASSERT_EQ(0, isqrt(0));
}
TEST(IntegerSquareRoot, one) {
  ASSERT_EQ(1, isqrt(1));
}
TEST(IntegerSquareRoot, rounded) {
  ASSERT_EQ(1, isqrt(2));
}
TEST(IntegerSquareRoot, larger_rounded) {
  ASSERT_EQ(11, isqrt(123));
}
TEST(IntegerSquareRoot, very_rounded) {
  ASSERT_EQ(11, isqrt(143));
}
TEST(IntegerSquareRoot, larger_unrounded) {
  ASSERT_EQ(11, isqrt(121));
}

TEST(IsPerm, length_missmatch) {
  ASSERT_EQ(false, is_perm(1234, 12343));
  ASSERT_EQ(false, is_perm(12343, 1234));
}
TEST(IsPerm, digit_miss) {
  ASSERT_EQ(false, is_perm(1231, 1232));
}
TEST(IsPerm, match) {
  ASSERT_EQ(true, is_perm(19642, 94162));
}
TEST(IsPerm, exact) {
  ASSERT_EQ(true, is_perm(12365, 12365));
}
TEST(IsPerm, single_digit) {
  ASSERT_EQ(true, is_perm(9, 9));
  ASSERT_EQ(false, is_perm(4, 9));
}

TEST(Choose, small) {
  ASSERT_EQ(10, choose(5,2));
}
TEST(Choose, one_edge) {
  for (int i = 0; i < 100; i++) {
    ASSERT_EQ(1, choose(i, 0));
  }
}
TEST(Choose, n_edge) {
  for (int i = 0; i < 100; i++) {
    ASSERT_EQ(1, choose(i, i));
  }
}
TEST(Choose, self_edge) {
  for (int i = 0; i < 100; i++) {
    ASSERT_EQ(i, choose(i, 1));
  }
}
TEST(Choose, large) {
  ASSERT_EQ(137846528820LL, choose(40, 20));
}
TEST(Choose, miss_match) {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < i; j++) {
      ASSERT_EQ(0, choose(j, i));
    }
  }
}

TEST(Length, power) {
  ASSERT_EQ(5, length(10000));
}
TEST(Length, near_power) {
  ASSERT_EQ(4, length(9999));
}
TEST(Length, zero) {
  ASSERT_EQ(1, length(0));
}
TEST(Length, one) {
  ASSERT_EQ(1, length(1));
}

TEST(Concat, zero) {
  ASSERT_EQ(10, concatenate(1, 0));
}
TEST(Concat, multi_digit) {
  ASSERT_EQ(1234, concatenate(12,34));
}
TEST(Concat, large) {
  ASSERT_EQ(1234567890, concatenate(12345,67890));
}

TEST(Figurate, ones) {
  for (int s = 3; s < 100; s++) {
    ASSERT_EQ(1, figurate_number(s, 1));
  }
}
TEST(Figurate, square) {
  ASSERT_EQ(16, figurate_number(4,4));
}
TEST(Figurate, triangle) {
  ASSERT_EQ(10, figurate_number(3, 4));
}
TEST(Figurate, large) {
  ASSERT_EQ(10132, figurate_number(20, 34));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
