#include "sub2/second.h"
#include "sub1/first.h"
#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(Mult, simple) {
  ASSERT_EQ(25, second_function(5,5));
  ASSERT_EQ(-25, second_function(-5,5));
}

TEST(Add, group) {
  for (int x = -100; x <= 100; x++) {
    for (int y = -100; y <= 100; y++) {
      ASSERT_EQ(x+y, first_function(x,y));
    }
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
