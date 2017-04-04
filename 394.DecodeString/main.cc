/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/03 21:00:47
 * @brief 
 * 
 **/ 

#include <cctype>
#include <string>
#include <iostream>

using namespace std;
// something wrong 
class Solution {
    public:
        string dfs(const string& s, int start, int end) {
            cout << "ENTER start=>" << start << "  end=>" <<  end << endl;
            string result = "";
            for( int i = start; i <= end;) {
                if (isalpha(s[i])) {
                    result += s[i++];
                    continue;
                }
                int n = 0;
                while (isdigit(s[i])) {
                    n = 10 * n + (s[i] - '0');
                    ++i;
                }
                // '['
                ++i;
                int left = i;
                while (s[i] != ']')  {
                    ++i;
                }
                auto str = dfs(s, begin, i - 1);
                cout << "i => " << i << endl;
                for (int j = 0; j < n; ++j) {
                    result += str;
                }
                while(']' == s[i]) {
                    ++i;
                }
            }

            cout << "EXIT start=>" << start << "  end=>" <<  end << endl;
            cout << "result => " << result << endl;
            return result;

        }
        string decodeString(string s) {
            return dfs(s, 0, s.size() - 1);
        }

};

int main(int argc, char *argv[]) {
    Solution s;
    {
        string input = "3[a2[c]]";
        cout << s.decodeString(input) << endl;
    }
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
