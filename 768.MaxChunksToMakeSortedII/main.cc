//
// Created by yinchunxiang on 2018/9/2.
//

#include <vector>

using namespace std;

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    if (arr.size() <= 1) return (int)arr.size();
    std::vector<int> left_max(arr.size(), arr.front());
    for (int i = 1; i < arr.size(); ++i) {
      left_max[i] = std::max(left_max[i - 1], arr[i]);
    }

    std::vector<int> right_min(arr.size(), arr.back());
    for (int i = (int)arr.size() - 2; i >= 0; --i) {
      right_min[i] = std::min(right_min[i + 1], arr[i]);
    }

    int count = 0;
    for (int i = 0; i < arr.size(); ++i) {
      if (i == arr.size() - 1) {
        count += 1;
        continue;
      }
      if (left_max[i] <= right_min[i + 1]) {
        count += 1;
      }
    }
    return count;

  }
};