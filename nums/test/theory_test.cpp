#include "../include/theory.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

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
