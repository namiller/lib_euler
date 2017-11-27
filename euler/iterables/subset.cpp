#include "subset.h"
#include <vector>

using namespace std;

void next_subset(int n, vector<int> &ss) {
  for (unsigned int i = 0; i < ss.size(); i++) {
    // we are at the end, or we have a gap.
    if (i == ss.size() - 1 || ss[i] != ss[i+1] - 1) {
      if (ss[i] < n) {
        ss[i]++;
      } else {
        i++;
      }
      for (unsigned int j = 0; j < i; j++) {
        ss[j] = j;
      }
      return;
    }
  }
}

