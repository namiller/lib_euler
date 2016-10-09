#include "iterables/subset.h"
#include "gtest/gtest.h"
#include <set>

using namespace std;

TEST(SubsetTest, uniques_size) {
  set<int> x = {1,2,3,4};
  int c = 0;
  for (const auto &v : subsets(x, 2)) {
    ASSERT_EQ(2, v.size());
    c++;
  }
  ASSERT_EQ(6, c); // 4c2 = 6
}

TEST(PermTest, correct_perms) {
  set<int> x = {1,2};
  SubsetIterable<int> s(x, 1);
  auto it = s.begin();
  ASSERT_EQ(set<int>({1}), *it);
  ++it;
  ASSERT_EQ(set<int>({2}), *it);
}
/*
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
*/
