//
// Created by alexkkk on 11/21/17.
//

#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        string output;
        size_t n = formula.size();
        // string => count
        int i = 0;
        //返回字符串出现的次数
        map<string, int> counts = parseFormula(formula, i);
        for (auto p : counts) {
            output += p.first;
            if (p.second > 1) output += to_string(p.second);
        }
    }

private:
    //
    map<string, int> parseFormula(string& s, int &i) {
        map<string, int> counts;
        size_t n = s.size();
        while (i < n && s[i] != ')') {
            map<string, int> cnts = parseUnit(s, i);
            merge(counts, cnts, 1);
        }
        return counts;
    }

    //unit指的是 ()digits, 或者UpperLowersdigits
    map<string, int> parseUnit(string &s, int &i) {
        map<string, int> counts;
        size_t n = s.size();
        if (s[i] == '(') {
            //括号内的又是一个formula，所以进行递归
            map<string, int> cnts = parseFormula(s, ++i);
            int digits = parseDigits(s, ++i);
            merge(counts, cnts, digits);
        } else {
            //第一个是大写字母
            int i0 = i++;
            while (i < n && islower(s[i])) i++;
            string atom = s.substr(i0, i - i0);
            int digits = parseDigits(s, i);
            counts[atom] += digits;
        }
        return counts;

    };

    int parseDigits(string &s, int &i) {
        int i1 = i;
        while (i < s.size() && isdigit(s[i])) ++i;
        int digits = (i == i1) ? 1 : stoi(s.substr(i1, i - i1));
        return digits;
    }

    void merge(map<string, int> &counts, map<string, int> &cnts, int times) {
        for (auto p : cnts) {
            counts[p.first] += p.second * times;
        }
    }
};