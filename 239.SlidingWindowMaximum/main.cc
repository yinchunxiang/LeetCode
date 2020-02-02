//
// Created by alexkkk on 2020/1/27.
//
#include <vector>
#include <deque>

#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> d;
    for (int i = 0; i < nums.size(); ++i) {
      dbg(d);
      dbg(result);
      // 去除范围外的
      while (!d.empty() && i - d.front() > k - 1) {
        d.pop_front();
      }
      // 去除不符合单调递减的
      while (!d.empty() && nums[d.back()] < nums[i]) {
        d.pop_back();
      }
      d.push_back(i);
      if (i >= k - 1) {
        result.push_back(nums[d.front()]);
      }
    }
    return result;

  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input = {1,3,-1,-3,5,3,6,7};
  dbg(s.maxSlidingWindow(input, 3));
  return 0;
}