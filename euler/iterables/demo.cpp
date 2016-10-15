#include <iostream>
#include <set>
#include <vector>
#include "euler/iterables/permutation.h"
#include "euler/iterables/subset.h"
#include "euler/serialize/printing.h"

using namespace std;
using namespace eul;

int main(){
  cout << to_string(subsets(set<int>({1,2,3}), 2)) << endl;
  cout << to_string(permutations(vector<int>({1,2,3}))) << endl;
  return 0;
}
