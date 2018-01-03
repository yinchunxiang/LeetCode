//
// Created by alexkkk on 11/28/17.
//

#include <string>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> s ;
        map<string, int> m;
        int i = 0;
        int n = (int)formula.size();
        while (i < n) {
            char c = formula[i++];
            if (c == '(') {
                //表示进入下一个，将之前的保存起来
                s.push(std::move(m));
                m = map<string, int>();
            } else if (c == ')') {
                int val = 0;
                while (i < n && isdigit(c)) {
                    val = val * 10 + (c - '0');
                    ++i;
                }
                if (0 == val) val = 1;
                if (s.empty()) continue;
                auto&& temp = std::move(m);
                auto&& m = s.top();
                s.pop();
                //将当前和合并到上一层，并将上一层的作为当前处理的
                for (auto p : temp) {
                    m[p.first] += p.second * val;
                }
            } else {
                int start = i - 1;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string atom = formula.substr(start, i - start);
                int val = 0;
                while (i < n && isdigit(formula[i])) val = val * 10 + (formula[i] - '0');
                if (0 == val) val = 1;
                m[atom] += val;
            }
        }
        string result;
        for (auto& p : m) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;

    }
};