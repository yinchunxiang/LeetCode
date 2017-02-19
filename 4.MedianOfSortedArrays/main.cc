/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/15 21:57:10
 * @brief 
 * 
 **/ 
#include <vector>
#include <iostream>

using namespace std;
 
class Solution {
    public:

        // always assume e1 - b1 < e2 - b2
        // 确认清楚k是从0还是从1开始
        double find_kth(vector<int> &nums1, int b1, vector<int> &nums2, int b2, int k) {
            cout << "b1 => " << b1 << "   b2 => " << b2 << "  k =>" << k << endl;
            int s1 = nums1.size() - b1;
            int s2 = nums2.size() - b2;
            if (s1 > s2) {
                cout << "s1 > s2" << endl;
                return find_kth(nums2, b2, nums1, b1, k);
            }
            if (0 == s1) {
                return nums2[k - 1];
            }
            if (1 == k) {
                return std::min(nums1[b1], nums2[b2]);
            }
            int l1 = min(s1, k/2);
            int ib1 = b1 + l1 - 1;
            int ib2 = b2 + k - l1 - 1;
            if (nums1[ib1] == nums2[ib2]) {
                return nums1[ib1];
            } else if (nums1[ib1] > nums2[ib2]) {
                return find_kth(nums1, b1, nums2, ib2 + 1, l1);
            } else {
                return find_kth(nums1, ib1 + 1, nums2, b2, k - l1);
            }
        }
            
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int total = nums1.size() + nums2.size();
            if (total & 0x1) {
                // odd
                return find_kth(nums1, 0, nums2, 0, total/2 + 1);
            } else {
                double l = find_kth(nums1, 0, nums2, 0, total/2);
                cout << "l => " << l << endl;
                double r = find_kth(nums1, 0, nums2, 0, total/2 + 1);
                cout << "r => " << r << endl;
                return l + (r - l)/2;
            }
                
        }

};


int main(int argc, char *argv[]) {
    vector<int> v1{1, 3};
    vector<int> v2{2, 4};
    Solution s;
    cout << s.findMedianSortedArrays(v1, v2) << endl;
        
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
