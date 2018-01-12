//
// Created by alexkkk on 1/12/18.
//

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:

    bool isDigit(const string& expression) {
        char first = expression[0];
        if ('-' == first || ('0' <= first && '9' >= first)) {
            return true;
        }
        return false;
    }

    string parse(string& s, int &start) {
        int temp = start;
        int end = start + 1;
        if ('(' == s[start]) {
            int count = 1;
            while (0 != count) {
                if ('(' == s[end]) {
                    count ++;
                } else if (')' == s[end]) {
                    count --;
                }
                end++;
            }
        } else {
            while (end < s.size() && ' ' != s[end]) {
                end ++;
            }
        }
        start = end + 1;
        return s.substr(temp, end - temp);

    }

    int help(string expression, unordered_map<string, int> myMap) {
        // 表达式是个数值
        if (isDigit(expression)) {
            return stoi(expression);
        }
        // expression是个变量
        if ('(' != expression[0]) {
            return myMap[expression];
        }
        // expression是括号括起来的表达式
        string s = expression.substr(1, expression.size() - 2);
        int start = 0;
        string word = parse(s, start);
        if (word == "let") {
            while (true) {
                string variable = parse(s, start);
                if (start > s.size()) return help(variable, myMap);
                string value = parse(s, start);
                myMap[variable] = help(value, myMap);
            }
        } else if ("add" == word) {
            return help(parse(s, start), myMap) + help(parse(s, start), myMap);
        } else if ("mult" == word) {
            return help(parse(s, start), myMap) * help(parse(s, start), myMap);
        } else {
            return help(word, myMap);
        }
    }


    int evaluate(string expression) {
        unordered_map<string, int> myMap;
        return help(expression, myMap);
    }
};


int main(int argc, char* argv[]) {
    //TODO
    string expression = "((add 1 2))";
    Solution s;
    cout << s.evaluate(expression) << endl;
    return 0;
}