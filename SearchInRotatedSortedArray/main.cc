//
// Created by alexkkk on 2019-03-16.
//
#include <vector>

using namespace std;


class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (target == nums[mid]) return mid;
      if (nums[mid] < nums[high]) { // 保证第一个判断的范围是 >= 2的，不然没有意义
        if (nums[mid] < target && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else {
        if (nums[low] <= target && target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
    }
    //if (target == nums[low]) return low;
    return -1;
  }
};
