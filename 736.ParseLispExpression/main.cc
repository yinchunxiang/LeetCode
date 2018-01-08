//
// Created by yinchunxiang on 05/01/2018.
//


#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string parse(const string& s, int& start) {
        int end = start + 1;
        int temp = start;
        // 表示嵌套层次
        int count = 1;
        // 说明里面还是一个()表达式
        if ('(' == s[start]) {
            while (0 != count) {
                if ('(' == s[end]) {
                    count ++;
                } else if (')' == s[end]) {
                    count --;
                }
                end ++;
            }
        } else {
            while (end < s.size() && ' ' != s[end]) {
                end ++;
            }
        }
        start = end + 1;
        return s.substr(temp, end - temp);

    }

    // 注意：必须使用传值
    int help(string expression, unordered_map<string, int> myMap) {
        // expression是个数值的情况
        if (('-' == expression[0]) || ('0' <= expression[0] && '9' >= expression[0])) {
            return stoi(expression);
        }
        // expression是个变量的情况
        if ('(' != expression[0]) {
            return myMap[expression];
        }
        // 解析()中间的部分
        string s = expression.substr(1, expression.size() - 2);
        int start = 0;
        string word = parse(s, start);
        if ("let" == word) {
            while (true) {
                string var = parse(s, start);
                if (start > s.size()) {
                    return help(var, myMap);
                }
                string value = parse(s, start);
                myMap[var] = help(value, myMap);
            }
        } else if ("add" == word) {
            return help(parse(s, start), myMap) + help(parse(s, start), myMap);

        } else if ("mult" == word) {
            return help(parse(s, start), myMap) * help(parse(s, start), myMap);
        }


    }
    int evaluate(string expression) {
        unordered_map<string, int> myMap;
        return help(std::move(expression), myMap);

    }

};
