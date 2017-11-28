//
// Created by yinchunxiang on 28/11/2017.
//

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
};

