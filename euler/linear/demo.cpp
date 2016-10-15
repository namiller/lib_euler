#include "euler/linear/matrix.h"
#include <iostream>

using namespace std;

int main(){
  auto m = Mat<int, 4>::Eye();
  auto m2 = m - m;
  auto m3 = Mat<int, 4>::Zeros();
  cout << (m2 == m3) << endl;
  return 0;
}
