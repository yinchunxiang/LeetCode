/****************************************************************************
 * 
 * Copyright (C) 2018 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2018/02/17 12:07:59
 * @brief 
 * 
 **/

#include <vector>
#include <numeric>
#include <list>
#include <iostream>

using namespace std;



class Solution {
public:

    int findMinMoves(vector<int>& machines) {
        auto n = machines.size();
        auto sum = accumulate(begin(machines), end(machines), 0);
        if (0 != sum % n) return -1;
        auto avg = sum / n;

        list<pair<int, int>> biggerList;
        for (int i = 0; i < n; ++i) {
            if (machines[i] <= avg) continue;
//            auto bigger = make_pair(i, machines[i] - avg);
//            biggerList.push_back(bigger);
            biggerList.emplace_back(i, machines[i] - avg);
            machines[i] = (int)avg;
        }
        int result = 0;
        for (int i = 0; i < n;) {
            if (machines[i] >= avg) {
                ++i;
                continue;
            }
            auto diff = avg - machines[i];
            auto bigger = biggerList.front();
            result += abs(i - bigger.first);
            if (diff == bigger.second) {
                ++i;
                biggerList.pop_front();
            } else if (diff < bigger.second) {
                bigger.second -= diff;
                ++i;
            } else {
                biggerList.pop_front();
                machines[i] += bigger.second;
            }
        }

        return result;

    }
};
 
int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {1, 0 , 5};
        cout << s.findMinMoves(input) << endl;

    }

    
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
