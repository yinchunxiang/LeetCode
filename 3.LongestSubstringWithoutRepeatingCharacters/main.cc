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
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
