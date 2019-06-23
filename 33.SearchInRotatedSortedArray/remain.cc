//
// Created by yinchunxiang on 2019-06-15.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
      // 左闭右开会保证 mid 左边的元素个数 >= mid右边的元素个数
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) return mid;
      if (low < mid && nums[low] <= nums[mid - 1]) { // 保证mid左边有元素
        if (nums[low] <= target && target <= nums[mid - 1]) {
          high = mid;
        } else {
          low = mid + 1;
        }
      } else if (mid + 1 < high && nums[mid + 1] <= nums[high - 1]) { // 保证mid右边有元素
        if (nums[mid + 1] <= target && target <= nums[high - 1]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      } else { // mid左右2边都没有元素
        return -1;
      }
    }
    return -1;
  }


  // 闭区间的写法
  int search1(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) return mid;
      if (low <= mid - 1 && nums[low] <= nums[mid - 1]) { // 会有只有一个元素的情况
        if (nums[low] <= target && target <= nums[mid - 1]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else  if (mid + 1 <= high && nums[mid + 1] <= nums[high]) {
        if (nums[mid + 1] <= target && target <= nums[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else {
        return -1;
      }
    }
    return -1;
  }


  // 左开右闭比较通用的写法，比较有助于解决81.SearchInRotatedSortedArrayII题数组中有重复的问题
  int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) return mid;
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
      } else { // 左边没有元素
        return -1;
      }
    }
    return -1;
  }
};


int main(int argc, const char *argv[]) {
//  vector<int> input = {4,5,6,7,0,1,2};
  vector<int> input = {3, 1};
  Solution s;
  cout << s.search(input, 0) << endl;

  return 0;
}
