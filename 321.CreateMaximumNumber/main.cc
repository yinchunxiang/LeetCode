/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/03 00:36:23
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;
 
class Solution {
    public:
        bool greater(vector<int> &l, int i, vector<int> &r, int j) {
            while (i < l.size() && j < r.size() && l[i] == r[j]) {
                i++;
                j++;
            }
            return j == r.size() || (i < l.size() && l[i] > r[j]);
        }

        vector<int> maxnum(vector<int> &v, int size) {
            int N = v.size();
            if (N <= size) {
                return v;
            }
            vector<int> s(size, 0);
            int top = 0;
            for (int i = 0; i < N; ++i) {
                // 出栈
                while (top > 0 && N - i + top > size && v[i] > s[top - 1]) {
                    top--;
                }
                if (top < size) {
                    s[top++] = v[i];
                }
            }
            return s;
        }

        vector<int> merge(vector<int> &v1, vector<int> &v2) {
            int m = v1.size();
            int n = v2.size();
            if (!m) {
                return v2;
            }
            if (!n) {
                return v1;
            }
            vector<int> result(m + n, 0);
            int i = 0; 
            int j = 0;
            int k = 0;
            while (i < m || j < n) {
                result[k++] = greater(v1, i, v2, j) ? v1[i++] : v2[j++];
            }
            return result;
        }



        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            int m = nums1.size();
            int n = nums2.size();
            vector<int> result(m + n, 0);
            for (int i = max(0, k - n); i <= min(m, k); i++) {
                vector<int> r1 = maxnum(nums1, i);
                vector<int> r2 = maxnum(nums2, k - i);
                vector<int> temp = merge(r1, r2);
                if (greater(temp, 0, result, 0)) {
                    result.swap(temp);
                }
            }
            return result;
        }

};


int main(int argc, char *argv[]) {
    
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
