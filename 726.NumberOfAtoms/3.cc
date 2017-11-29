//
// Created by yinchunxiang on 28/11/2017.
//

#include <string>
#include <map>

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
    void merge(map<string, int>& counts, map<string, int>& cnt, int times) {
        for (auto& p : cnt) {
            counts[p.first] += p.second * times;
        }
    }

    int parseDigits(const string& s, int& i) {
        int start = i;
        while (i < s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
            ++i;
        }
        int digits = (start == i) ? 1 : stoi(s.substr(start, i - start));
        return digits;
    }

    map<string, int> parseFormula(const string& s, int& i) {
        int n = (int) s.size();
        map<string, int> counts;
        while (i < n && s[i] != ')') {
            map<string, int> cnt = parseUnit(s, i);
            merge(counts, cnt, 1);
        }
        return counts;
    }

    map<string, int> parseUnit(const string& s, int& i) {
        map<string, int> counts;
        if ('(' == s[i]) {
            map<string, int> cnt = parseFormula(s, ++i);
            int digits = parseDigits(s, ++i);
            merge(counts, cnt, digits);
        } else {
            int start = i++;
            while (i < s.size() && islower(static_cast<unsigned char>(s[i]))) {
                ++i;
            }
            string atom = s.substr(start, i - start);
            int digits = parseDigits(s, i);
            counts[atom] += digits;
        }
        return counts;
    };
};

