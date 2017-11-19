//
// Created by yinchunxiang on 19/11/2017.
//

#include <string>
#include <map>
#include <iostream>

using namespace std;

void print_map(const map<string, int> &mymap) {
    for (auto p : mymap) {
        cout << p.first << " => " << p.second << endl;
    }
}

class Solution {
public:
    string mapToString(map<string, int> &m) {
        string result;
        for (auto it = m.begin(); it != m.end(); ++it) {
            result += it->first;
            if (it->second > 1) {
                result += to_string(it->second);
            }
        }
        return result;
    }

    string countOfAtoms(string formula) {
        map<string, int> result = count(formula);
        print_map(result);
        return mapToString(result);
    }

    map<string, int> count(string formula) {
        map<string, int> result;
        int n = (int) formula.size();
        string rest = "";
        for (int i = 0; i < n; ) {
            char c = formula[i];
            if (')' != c) {
                rest.push_back(c);
                ++i;
                continue;
            }
            string mid = "";
            while ('(' != rest.back()) {
                mid = rest.back() + mid;
                rest.pop_back();
            }
            //pop (
            rest.pop_back();
//            cout << "mid: " << mid << endl;
            map<string, int> midmap = getSimpleFormularList(mid);
            int count = 0;
            // jump )
            ++i;
            while (i < n && isdigit(formula[i])) {
                count = count * 10 + (formula[i] - '0');
                ++i;
            }
//            cout << "count: " << count << endl;
            if (count > 1) {
                for (auto &p : midmap) {
                    p.second *= count;
                }
            }
            string midstr = mapToString(midmap);
            rest += midstr;
        }
//        cout << "rest: " << rest << endl;
        if (rest.empty()) {
            return result;
        }
        map<string, int> restMap = getSimpleFormularList(rest);
        for (auto p : restMap) {
            result[p.first] += p.second;
        }
        return result;
    };

    map<string, int> getSimpleFormularList(string complexFormula) {
        map<string, int> result;
        string key = "";
        int count = 0;
        for (int i = 0; i <= complexFormula.size(); ++i) {
            if (i == complexFormula.size()) {
                if (!key.empty()) {
                    if (count > 0) {
                        result[key] += count;
                    } else {
                        result[key] += 1;
                    }
                }
                break;
            }
            char c = complexFormula[i];
            if (isalpha(c)) {
                if (c >= 'A' && c <= 'Z') {
                    if (!key.empty()) {
                        if (count > 0) {
                            result[key] += count;
                        } else {
                            result[key] += 1;
                        }
                    }
                    key = "";
                    count = 0;
                }
                key += c;
            } else {
                count = 10 * count + (c - '0');
            }

        }
        return result;
    }
};



int main(int argc, char *argv[]) {
    Solution s;
    /*
    {
        cout << s.countOfAtoms("H2O") << endl;
    }
    {
        cout << s.countOfAtoms("SO3") << endl;
    }
    {
        cout << s.countOfAtoms("SO3H") << endl;
    }
    {
        cout << s.countOfAtoms("Mg(OH)2") << endl;
    }
     */
    {
        cout << s.countOfAtoms("K4(ON(SO)2)2") << endl;
    }
    return 0;
}
