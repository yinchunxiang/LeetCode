/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/23 23:00:46
 * @brief 
 * 
 **/ 

#include <iostream>
#include <queue>

using namespace std;
 
class Solution {
    public:
        int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
            auto cmp1 = [](const pair<int, int>& l, const pair<int, int> &r) {return l.first > r.first;};
            //priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(const pair<int, int>& l, const pair<int,int> &r)>> cq(cmp1);
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> cq(cmp1);
            auto cmp2 = [](const pair<int, int> &l, const pair<int, int> &r) {return l.second < r.second;};
            //priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(const pair<int, int>& l, const pair<int,int> &r)>> pq(cmp2);
            priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp2)> pq(cmp2);

            for (int i = 0; i < Profits.size(); ++i) {
                cq.push(pair<int, int>(Capital[i], Profits[i]));
            }

            int current_capital = W;

            while (k-- > 0) {
                while (!cq.empty() && cq.top().first <= current_capital) {
                        pq.push(cq.top());
                        cq.pop();
                }
                if (pq.empty()) {
                    //没有能做的项目
                    break;
                }
                current_capital += pq.top().second;
                pq.pop();
            }
            return current_capital;
        }

};



int main(int argc, char *argv[]) {
    {
        Solution sol;
        vector<int> profits = {1, 2, 3};
        vector<int> capital = {0, 1, 1};
        cout << sol.findMaximizedCapital(2, 0, profits, capital) << endl;
    }
    return 0;
}









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
