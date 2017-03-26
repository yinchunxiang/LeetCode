/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/26 10:51:24
 * @brief 
 * 
 **/ 

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
    public:
        bool checkPerfectNumber(int num) {
            if (1 == num) {
                return false;
            }
            int s = sqrt(num);
            int sum = 1;
            for (int i = 2; i <= s; ++i) {
                if (num % i == 0) {
                    if (i != num/i) {
                        sum += i + num/i;
                    } else {
                        sum += i;
                    }
                    cout << "added " << i << " " << num/i << endl;
                }

            }
            cout << "sum => " << sum << endl;
            return sum == num;
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.checkPerfectNumber(6) << endl;
    return 0;
}












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
