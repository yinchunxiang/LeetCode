//
// Created by yinchunxiang on 28/11/2017.
//

#include <string>
#include <map>
#include <locale>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        string output;
        int i = 0;
        map<string, int> counts = parseFormula(formula, i);
        for (auto p : counts) {
            output += p.first;
            if (p.second > 1) {
                output += to_string(p.second);
            }
        }
        return output;

    }

private:
    //解析()内的部分
    map<string, int> parseFormula(const string& s, int& i) {
        map<string, int> counts;
        int n = (int)s.size();
        while(i < n && s[i] != ')') {
            map<string, int> cnt = parseUnit(s, i);
            merge(counts, cnt, 1);
        }
        return counts;
    }

    //解析UpperLowersDigits
    map<string, int> parseUnit(const string& s, int& i) {
        map<string, int> counts;
        int n = (int) s.size();
        if ('(' == s[i]) {
            map<string, int> cnt = parseFormula(s, ++i);
            //parseFormula结束的时候，i指向')'
            int digits = parseDigits(s, ++i);
            merge(counts, cnt, digits);
        } else {
            int start = i++;
            while (i < n && std::islower(s[i])) { ++i; }
            string atom = s.substr(start, i - start);
            int digits = parseDigits(s, i);
            counts[atom] += digits;
        }
        return counts;
    };

    void merge(map<string, int>& counts, const map<string, int>& cnt, int times) {
        for (auto& p : cnt) {
            counts[p.first] += p.second * times;
        }
    }

    int parseDigits(const string& s, int& i) {
        int start = i;
        while (i < s.size() && isdigit(s[i])) {
            ++i;
        }
        int digits = (start == i) ? 1 : stoi(s.substr(start, i - start));
        return digits;
    }

};
