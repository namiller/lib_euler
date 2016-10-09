#include "introspection/containers.h"
#include "gtest/gtest.h"
#include <vector>
#include <set>

using namespace std;
using namespace eul;

contained_type_or<int, void>::type test1() {
  return;
}

contained_type_or<vector<int>, void>::type test2() {
  return 1;
}

TEST(Templates, container) {
  bottom_type<int>::type a = 3.0;
  ASSERT_EQ(3, a);
  bottom_type<vector<int> >::type b = 3.0;
  ASSERT_EQ(3, b);
  bottom_type<vector<vector<int> > >::type c = 3.0;
  ASSERT_EQ(3, c);
}

