/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 11:05:55
 * @brief 
 * 
 **/ 

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

 
class Solution {
    public:
        int minutes(string& str) {
            int hours = atoi(str.substr(0, 2).c_str());
            int minute = atoi(str.substr(3, 2).c_str());
            return hours * 60 + minute;
        }
        int findMinDifference(vector<string>& timePoints) {
            sort(timePoints.begin(), timePoints.end());
            int mode = 1440;
            int result = mode;
            for (int i = 1; i < timePoints.size(); ++i) {
                
                int a = minutes(timePoints[i]);
                //cout << "a => " << a << endl;
                int b = minutes(timePoints[i - 1]);
                int diff = 1440;
                if (0 == b) {
                    diff = min(a - b, mode - a);
                } else {
                    diff = a - b;
                }
                //cout << "b => " << b << endl;
                if (0 == diff) {
                    return 0;
                }
                result = min(result, diff);
            }
            int second = minutes(timePoints[0]) + mode;
            int first = minutes(timePoints.back());
            int diff = second - first;
            
            return min(result, diff);
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<string> input = {"12:12", "00:13"};
        cout << s.findMinDifference(input) << endl;
    }
    {
        vector<string> input = {"23:59", "00:00"};
        cout << s.findMinDifference(input) << endl;
    }
    {
        vector<string> input = { "05:31","22:08","00:35" };
        cout << s.findMinDifference(input) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
