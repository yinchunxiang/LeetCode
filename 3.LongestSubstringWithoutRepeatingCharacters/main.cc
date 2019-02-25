/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/10 15:56:20
 * @brief 
 * 
 **/

#include <string>

#include <vector>
#include <map>

using namespace std;

 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter = 0; // check whether the substring is valid
        // 最优符合条件的子串的开始位置
        int start = 0;
        int d = 0; //the length of substring
        int curStart=0, curEnd=0; //two pointers, one point to tail and one  head

        while(curEnd < s.size()){
            // 
            if(map[s[curEnd++]]++ > 0){
                counter ++;
            }

            // counter > 0 代表出现重复
            while(count > 0){
                if(map[s[curStart++]]-- > 1){
                    // 去除重复
                    counter --;
                }
            }
            // 满足条件，没有重复了，更新d
            d = max(d, curEnd - curStart);

            /* update d here if finding maximum*/
        }
        return d;
    }
    int solve(string s) {
      int n = (int)s.size();
      if (n < 2) return n;
      vector<int> count(256, 0);
      int max_len = 0;
      int start = 0;
      for (int i = 0; i < n; ++i) {
        if (++count[s[i]] > 1) { // 出现重复
          // 计算新的长度
          max_len = max(max_len, i - start);
          // 计算新的start
          while (count[s[i]] > 1) {
            count[s[start++]] --;
          }
        }
      }
      // 注意考虑结束的问题
      max_len = std::max(max_len, n - start);
      return max_len;

    }

    int solve1(string s) {
      // leetcode 上有个更进一步的nb解法
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
