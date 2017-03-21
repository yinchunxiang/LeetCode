/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/19 12:59:30
 * @brief 
 * 
 **/ 

#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

void printv(const std::vector<string> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
 
class Solution {
    public:

        string join(const string& l, const string& r) {
                string result = "(";
                result += l;
                result += ",";
                result += r;
                result += ")";
                return result;
        }
        string help(vector<string> &input) {
            printv(input);
            int size = input.size();
            if (0 == size) {
                return "";
            }
            if (1 == size) {
                return input[0];
            }
            if (2 == size) {
                return join(input[0], input[1]);
            }
            int left = 0;
            int right = size - 1;

            vector<string> bak;
            while (input.size() >= 2) {
                int left = 0;
                int right = input.size() - 1;
                while (left < right) {
                    string s = join(input[left++], input[right--]);
                    cout << "join => " << s << endl;
                    bak.push_back(s);
                }
                if (left == right) {
                    bak.push_back(input[left]);
                }
                swap(input, bak);
                bak.clear();
            }
            return input[0];
        }
        string findContestMatch(int n) {
            vector<string> input;
            for (int i = 1; i <= n; ++i) {
                input.push_back(std::to_string(i));
            }
            return help(input);

        }

};


int main(int argc, char *argv[]) {
    Solution s;
    {
        cout << s.findContestMatch(2) << endl;
    }
    {
        cout << s.findContestMatch(4) << endl;
    }
    {
        cout << s.findContestMatch(8) << endl;
    }
    return 0;
}










/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
