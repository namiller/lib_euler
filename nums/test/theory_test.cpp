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
TEST(ContinuingSqrt, repeating_two) {
  ASSERT_EQ(vector<int>({1,2}), continuing_fraction_sqrt(2));
}
TEST(ContinuingSqrt, odd_length) {
  ASSERT_EQ(vector<int>({2,2,4}), continuing_fraction_sqrt(6));
}
TEST(ContinuingSqrt, odd_long) {
  ASSERT_EQ(vector<int>({8,1,1,1,16}), continuing_fraction_sqrt(75));
}

/*
TEST(ExtendedGCD, no_repeat) {
  ASSERT_EQ(make_pair(1,2), extended_gcd(5,2));
}*/

TEST(Totient, perfect) {
  ASSERT_EQ(8, totient(24));
}

TEST(Totient, squart) {
  ASSERT_EQ(3, totient(9));
}

TEST(ModExp, no_mod) {
  ASSERT_EQ(5*5*5*5, mod_exp(5,4,10000));
  ASSERT_EQ(1234*1234, mod_exp(1234,2,100000000));
}

TEST(ModExp, zero_remainder) {
  ASSERT_EQ(0, mod_exp(10,12312, 1000));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
