#include "serialize/printing.h"
#include "gtest/gtest.h"

#include <vector>
#include <list>
#include <utility>
#include <set>
#include <map>
#include <typeinfo>

using namespace std;
using namespace eul;

string my_adapter(float f) {
  return p_adapter(f, 1);
}

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

TEST(Vector, OneD) {
  ASSERT_EQ("[1, 2, 3, 4, 5, 6]", to_string(vector<int>({1,2,3,4,5,6})));
  ASSERT_EQ("[1, 2, 3, 4, 5, 6]", to_string(vector<int>({1,2,3,4,5,6}),id_adapter<int>));
  ASSERT_EQ("[1.0, 2.0, 3.0, 4.0, 5.0, 6.0]", to_string(vector<float>({1,2,3,4,5,6}), p_adapter<1, float>));
  ASSERT_EQ("[one, two, three, four, five, six]", to_string(vector<string>({"one","two","three","four","five","six"}), id_adapter<string>));
}

TEST(List, OneD) {
  ASSERT_EQ("[1, 2, 3, 4, 5, 6]", to_string(list<int>({1,2,3,4,5,6})));
}

TEST(Set, OneD) {
  ASSERT_EQ("[1, 2, 3, 4, 5, 6]", to_string(set<int>({1,2,3,4,5,6})));
}

TEST(Map, OneD) {
  map<int, int> m;
  m[0] = 1;
  m[4] = 3;
  ASSERT_EQ("[<0, 1>, <4, 3>]", to_string(m, pair_adapter));
}

TEST(Vector, TwoD) {
  ASSERT_EQ("[[1, 2, 3, 4, 5, 6], [2]]", to_string(vector<vector<int> >({{1,2,3,4,5,6},{2}})));
}

TEST(Adapter, precision) {
  ASSERT_EQ("1.00", p_adapter(static_cast<float>(1),2));
  ASSERT_EQ("1.00", p_adapter<2>(static_cast<float>(1)));
  ASSERT_EQ("1.00", p_adapter(static_cast<double>(1),2));
  ASSERT_EQ("0.33", p_adapter(static_cast<double>(1.0/3.0),2));
}
