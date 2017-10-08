/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/10/08 23:23:35
 * @brief 
 * 
 **/

#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    unordered_map<int, bool> m;
    int maxn;

    bool canWin(int total, int visited) {
        if (m.find(visited) != m.end()) {
            return m[visited];
        }
        for (int i = 1; i <= maxn; ++i) {
            int mask = (1 << i);
            // 已经使用过的数字，跳过
            if ((mask & visited) != 0) {
                continue;
            }
            if (i >= total || !canWin(total - i, mask | visited)) {
                m[visited] = true;
                return true;
            }
        }
        //没有找到成功的方法
        m[visited] = false;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        maxn = maxChoosableInteger;
        if (maxn >= desiredTotal) return true;
//        if (maxChoosableInteger + 1 >= desiredTotal) return false;
        if (maxn * (maxn + 1)/2 < desiredTotal) {
            return false;
        }
        return canWin(desiredTotal, 0);
    }
};



int main(int argc, char *argv[])
{

    Solution s;
    cout << "result: " << s.canIWin(10, 40) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
