//
// Created by yinchunxiang on 2019-06-15.
//


// yinchunxiang@2019/06/15: 思路来源可参照 33.SearchInRotatedSortedArray题
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) return true;
      if (nums[low] < nums[mid]) { // mid 左边至少一个元素, 且顺序OK
        // 顺序OK就从当前这边判断
        if (nums[low] <= target && target < nums[mid]) {
          high = mid;
        } else {
          low = mid + 1;
        }
      } else if (nums[low] > nums[mid]) { // mid 左边至少一个元素， 且顺序不OK
        // 顺序不OK就从另外一边判断
        if (nums[mid] < target && target <= nums[high - 1]) { // 右边至少一个元素的情况
          low = mid + 1;
        } else {
          high = mid;
        }
      } else if (nums[low] == nums[mid]){ // 左边元素和mid元素相等
        // low 和 mid 重复了，跳过
        low += 1;
      } else { // 左边没有元素
        return false;
      }
    }
    return false;
  }
};