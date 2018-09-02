//
// Created by yinchunxiang on 2018/9/2.
//

#include <vector>

using namespace std;

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int count = 0;
    int left_max = 0;
    for (int i = 0; i < arr.size(); ++i) {
      left_max = std::max(left_max, arr[i]);
      if (left_max <= i) {
        count += 1;
      }
    }
    return count;
  }
};