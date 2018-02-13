/****************************************************************************
 * 
 * Copyright (C) 2018 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2018/02/07 10:32:14
 * @brief 
 * 
 **/

using namespace std;

#include <string>
#include <vector>
#include <iostream>

/**
 * 思路说明：
 * 1. 先找到specail string， 要求 1的个数和0的个数相同，通过count计数得到
 * 2. 然后保证当前special string内部的specail string也经过了排序，得到了最大的顺序
 * 3. 最后保证special string之间的顺序
 * 总结：递归
 */


class Solution {
    public:
        string makeLargestSpecial(string S, int level) {
            cout << "--> level: "<< level << " input: " << S << endl;
            size_t count = 0;
            size_t start = 0;
            vector<string> result;
            for (size_t i = 0; i < S.size(); ++i) {
                if ('1' == S[i]) count ++;
                else count --;
                // 找打special string
                if (0 == count) {
                    //1. S的第一个数字必然为1， 不然不满足special string的条件
                    //2. 在0 == count的时候，当前的数字必然是0
                    result.push_back(
                            '1' + makeLargestSpecial(S.substr(start + 1, i-start-1), level + 1) + '0'
                    );
                    start = i + 1;
                }
            }
            sort(begin(result), end(result), greater<string>());
            string str = "";
            for (const auto& s : result) { str += s; }
            cout << "--> level: "<< level << " output: " << str << endl;
            return str;
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    cout << s.makeLargestSpecial("11011000", 0) << endl;
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
