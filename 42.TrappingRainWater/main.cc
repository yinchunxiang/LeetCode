/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 17:55:11
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
    public:
        int trap(vector<int>& height) {
            // 用vector模拟单调栈
            vector<int> v;
            int N = height.size();
            int sum = 0;
            for (int i = 0; i < N; ++i) {
                //栈为空，则直接插入 
                if (v.empty()) {
                    v.push_back(i);
                    continue;
                }

                // 当前元素 >= 栈顶元素
                if (height[i] >= height[v.back()]) {
                    while (!v.empty() && height[i] > height[v.back()]) {
                        //栈顶元素作为最低点
                        int bar = height[v.back()];
                        v.pop_back();
                        if (!v.empty()) {
                            int l = i - v.back() - 1;
                            int h = min(height[i], height[v.back()]) - bar;
                            sum += l * h;
                        }
                    }
                }
                v.push_back(i);
            }
            return sum;
        }
};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = { 0,1,0,2,1,0,1,3,2,1,2,1 };
        cout << s.trap(input) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
