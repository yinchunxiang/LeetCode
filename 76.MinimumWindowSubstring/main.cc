/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/10 12:27:59
 * @brief 
 * 
 **/ 

class Solution {
    public:
        string minWindow(string s, string t) {
            vector<int> map(128, 0);
            for (auto c : t){
                map[c] ++;
            }
            int counter = t.size();
            int d = INT_MAX;
            int start = 0;

            int curStart = 0;
            int curEnd = 0;

            for (;curEnd < s.size(); ) {
                char c = s[curEnd];
                if (map[c] > 0) {
                    counter --;
                }
                //
                map[c] --;
                curEnd ++;
                
                while (0 == counter) {
                    if (curEnd - curStart < d) {
                        d = curEnd - curStart;
                        start = curStart;
                    }
                    char ch = s[curStart];
                    if (map[ch] == 0) {
                        counter ++;
                    }
                    curStart ++;
                    map[ch] ++;
                }
            }
            if (d == INT_MAX) {
                return "";
            }

            return s.substr(start, d);
        }



};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
