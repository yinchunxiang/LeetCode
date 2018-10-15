//
// Created by yinchunxiang on 2018/9/2.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  using It = std::vector<int>::iterator;

  int findKth(It begin1, It end1, It begin2, It end2, int k) {
    cout << "size1: " << end1 - begin1 << " size2: " << end2 - begin2 << endl;
    if (begin1 != end1 && begin2 != end2) {
      cout << "begin1: " << *begin1 << " begin2: " << *begin2 << " k: " << k << endl;
    }
    if (begin1 == end1) {
      return *(begin2 + k - 1);
    }
    if (begin2 == end2) {
      return *(begin1 + k - 1);
    }

    if (1 == k) {
      return std::min(*begin1, *begin2);
    }

    int m = (k/2 > end1 - begin1) ? end1 - begin1 : k/2;
    int n = k - m;

    auto mid1 = begin1 + m - 1;
    auto mid2 = begin2 + n - 1;

    if (*mid1 == * mid2) {
      return *mid1;
    }
    if (*mid1 > *mid2) {
      return findKth(begin1, mid1 + 1, mid2 + 1, end2, k - n);
    }
    return findKth(mid1 + 1, end1, begin2, mid2 + 1, k - m);






//    if (k % 2 == 0) {
//      if (k/2 > end1 - begin1)
//      auto mid1 = begin1 + k/2 - 1;
//      auto mid2 = begin2 + k/2 - 1;
//      if (*mid1 == *mid2) {
//        return *mid1;
//      }
//      if (*mid1 > *mid2) {
//        return findKth(begin1, mid1 + 1, mid2 + 1, end2, k - k/2);
//      }
//      return  findKth(mid1 + 1, end1, begin2, mid2 + 1, k - k/2);
//    }

//    auto mid1 = begin1 + k/2;
//    auto mid2 = begin2 + k/2;
//    if (*mid1 == *mid2) return *mid1;
//    if (*mid1 > *mid2) {
//      return findKth(begin1, mid1, mid2, end2, k - k/2);
//    }
//    return  findKth(mid1, end1, begin2, mid2, k - k/2);
  }


  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 保证短的在前面
    if (nums1.size() > nums2.size()) {
      nums1.swap(nums2);
    }
    int size = nums1.size() + nums2.size();
    if (1 == size) return nums2[0];
    if (size % 2 == 0) {
      return 1.0 * (findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), size/2)
          + findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), size/2 + 1) )/2;
    }
    return findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), size/2 + 1) ;
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  }
  cout << "=================" << endl;
  {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  }
  cout << "=================" << endl;
  {
    vector<int> nums1 = {3};
    vector<int> nums2 = {1, 2, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  }
  cout << "=================" << endl;
  {
    vector<int> nums1 = {};
    vector<int> nums2 = {2, 3};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  }
  cout << "=================" << endl;
  {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  }
  return 0;
}
