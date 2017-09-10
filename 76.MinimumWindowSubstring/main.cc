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
            if (s.empty() || t.empty()) {
                return "";
            }

            if (s.size() < t.size()) {
                return "";
            }

            if (s.size() == t.size()) {
                if (s == t) {
                    return s;
                }
                return "";
            }

            vector<int> map(256, 0);
            for (auto c : t){
                map[c] ++;
            }

            int counter = t.size();

            int d = INT_MAX;
            int start = 0;
            int end = s.size() - 1;

            int curStart = 0;
            int curEnd = 0;


            for (;curEnd < s.size();) {
                if (map[s[curEnd++]]-- > 0) {
                    counter --;
                }

                while (0 == counter) {
                    if (curEnd - curStart < d) {
                        d = curEnd - curStart;
                        start = curStart;
                        end = curEnd;
                    }
                    if (map[s[curStart]] > 0) {

                    }
                }


                record[s[curEnd]] += 1;
                auto it = map.find(s[curEnd]);
                if (it == map.end()) {
                    curEnd++;
                    continue;
                }
                --(it->second);
                if (0 == it->second) {
                    map.erase(it);
                }
                if (!map.empty()) {
                    continue;
                }

                for (;curStart < curEnd;) {
                    auto iter = tCharCountMap.find(s[curStart]);
                    if (iter == tCharCountMap.end()) {
                        ++curStart;
                        continue;
                    }
                    if (record[s[curStart]] > iter->seond) {
                        record[s[curStart]] --;
                        continue;
                    }
                    break;
                }

                if (curEnd - curStart < end - start) {
                    start = curStart;
                    end = curEnd;
                }

                map = tCharCountMap;
            }

            return s.substr(start, end - start + 1);
        }



};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
