/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/27 22:34:51
 * @brief 
 * 
 **/ 


#include <vector>
#include <iostream>

using namespace std;
void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
    public:
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            int N = people.size();
            auto cmp = [](const pair<int, int>& l, const pair<int, int> &r) { return l.first < r.first || (l.first == r.first && l.second < r.second); };
            sort(people.begin(), people.end());
//            for (auto & p : people) {
//                cout << "(" << p.first << "," << p.second << ")" << endl;
//            }
            vector<int> counts(N, 0);
            for (int i = 1; i < N; ++i) {
                if (people[i].first == people[i - 1].first) {
                    counts[i] = counts[i - 1]  + 1;
                }
            }
            //printv(counts);

            for (int i = N - 1; i >= 0; --i) {
                // 没法调整了
                if (counts[i] == people[i].second) {
                    continue;
                }
                int j = i + 1;
                int maxj = i + people[i].second - counts[i];
                auto p = people[j - 1];
                for (; j <= maxj; ++j) {
                    //cout << "j = " << j << endl;
                    //cout << "people[" << i << "].second = " << people[i].second << endl;
                    //cout << "conts[" << i << "] = " << counts[i] << endl;
                    people[j - 1] = people[j];
                }
                people[j - 1] = p;
                //for (auto & p : people) {
                //    cout << "(" << p.first << "," << p.second << ")";
                //}
                //cout << endl;
            }
            return people;
        }

};

int main(int argc, char *argv[]) {
    {
        vector<pair<int, int>> input;
        input.push_back(pair<int, int>(7, 0));
        input.push_back(pair<int, int>(4, 4));
        input.push_back(pair<int, int>(7, 1));
        input.push_back(pair<int, int>(5, 0));
        input.push_back(pair<int, int>(6, 1));
        input.push_back(pair<int, int>(5, 2));
        Solution sol;
        auto result = sol.reconstructQueue(input);
        for (auto & p : result) {
            cout << "(" << p.first << "," << p.second << ")" << endl;
        }

    }

    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
