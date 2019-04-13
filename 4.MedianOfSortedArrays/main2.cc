//
// Created by yinchunxiang on 2019-04-12.
//

/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

/**
 * Time Complexity: O(log(M+N))
 * Space Complexity: O(log(M+N) 递归深度
 */
 

class Solution {
 public:
  // k是从1开始的
  // 这个里面将没有交集的一起处理了，但是时间肯定相对长一些
  int findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
    // 将比较短的放到前面
    int s1 = nums1.size() - start1;
    int s2 = nums2.size() - start2;
    if (s1 > s2) {
      return findKth(nums2, start2, nums1, start1, k);
    }
    if (0 == s1) return nums2[start2 + k - 1];
    if (1 == k) return min(nums1[start1], nums2[start2]);
    auto l1 = min(s1, k/2);
    auto l2 = k - l1;
    auto k1 = start1 + l1 - 1;
    auto k2 = start2 + l2 - 1;
    if (nums1[k1] == nums2[k2]) {
      return nums1[k1];
    }
    if (nums1[k1] > nums2[k2]) {
      return findKth(nums1, start1, nums2, k2 + 1, k - l2);
    }
    return findKth(nums1, k1 + 1, nums2, start2, k - l1);
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    if (total %2 != 0) {
      return findKth(nums1, 0, nums2, 0, total/2 + 1);
    }
    auto med1 = findKth(nums1, 0, nums2, 0, total/2);
    auto med2 = findKth(nums1, 0, nums2, 0, total/2 + 1);
    return ((double)med1 + (double)med2)/2;
  }
};