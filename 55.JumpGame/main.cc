/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/18 14:53:58
 * @brief 
 * 
 **/

#include <vector>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
          // 前一个位置能达到的最大位置
            int reach = 0;
            int n = (int)nums.size();
            for (int i = 0; i < n; ++i) {
              // 计算当前位置能达到的最大位置
                reach = max(reach, i + nums[i]);
                if (reach >= n - 1) {
                    return true;
                }
                if (reach < i + 1) {
                    return false;
                }
            }
            return true;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
