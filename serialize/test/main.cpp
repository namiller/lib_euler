#include "../include/printing.h"
#include <gtest/gtest.h>
#include <vector>
#include <typeinfo>

using namespace std;

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
  //ASSERT_EQ( true, type_id<contained_type<vector<int> >::type> == type_id<int>);
}

TEST(Vector, OneD) {
  //string x = test(vector<int>());
  //contained_type<vector<int> >::type x = "hi";
  //cout << to_string(vector<int>({1,2,3}));
  //cout << to_string(int(1), id_adapter<int>);
  ASSERT_EQ("[1, 2, 3, 4, 5, 6]", to_string(vector<int>({1,2,3,4,5,6})));
  ASSERT_EQ("[1, 2, 3, 4, 5, 6]", to_string(vector<int>({1,2,3,4,5,6}),id_adapter<int>));
  ASSERT_EQ("[1.0, 2.0, 3.0, 4.0, 5.0, 6.0]", to_string(vector<float>({1,2,3,4,5,6}), my_adapter));
  ASSERT_EQ("[one, two, three, four, five, six]", to_string(vector<string>({"one","two","three","four","five","six"}), id_adapter<string>));
}

TEST(Vector, TwoD) {
  ASSERT_EQ("[[1, 2, 3, 4, 5, 6], [2]]", to_string(vector<vector<int> >({{1,2,3,4,5,6},{2}})));
  //ASSERT_EQ("[1.0, 2.0, 3.0, 4.0, 5.0, 6.0]", to_string(vector<float>({1,2,3,4,5,6})));
  //ASSERT_EQ("[one, two, three, four, five, six]", to_string(vector<string>({"one","two","three","four","five","six"})));
}

TEST(Adapter, precision) {
  ASSERT_EQ("1.00", p_adapter(static_cast<float>(1),2));
  ASSERT_EQ("1.00", p_adapter(static_cast<double>(1),2));
  ASSERT_EQ("0.33", p_adapter(static_cast<double>(1.0/3.0),2));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
