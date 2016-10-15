#include "euler/iterables/permutation.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(PermTest, uniques_size) {
  vector<int> x = {1,2,3,4};
  int c = 0;
  for (const auto &v : permutations(x)) {
    ASSERT_EQ(4, v.size());
    c++;
  }
  ASSERT_EQ(4*3*2*1, c); // n! perms of n unique elms
}

TEST(PermTest, redund_size) {
  vector<int> x = {1,2,3,4,4};
  int c = 0;
  for (const auto &v : permutations(x)) {
    ASSERT_EQ(5, v.size());
    c++;
  }
  // n!/p_r(s!) perms of n elms with r redundancy groups of size s
  ASSERT_EQ(5*4*3*2*1 / 2, c);
}

TEST(PermTest, correct_perms) {
  vector<int> x = {1,2};
  PermutationIterable<int> s(x);
  auto it = s.begin();
  ASSERT_EQ(vector<int>({1,2}), *it);
  ++it;
  ASSERT_EQ(vector<int>({2,1}), *it);
}

TEST(PermTest, edge0) {
  vector<int> x = {};
  int c = 0;
  for (const auto &v : permutations(x)) {
    ASSERT_EQ(0, v.size());
    c++;
  }
  ASSERT_EQ(1, c);
}

TEST(PermTest, edge1) {
  vector<int> x = {1};
  int c = 0;
  for (const auto &v : permutations(x)) {
    ASSERT_EQ(1, v.size());
    c++;
  }
  ASSERT_EQ(1, c);
}

