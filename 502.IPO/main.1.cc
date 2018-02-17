//
// Created by alexkkk on 2/13/18.
//



#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        // 按照capital排序
        // 注意: priority_queue使用的排序函数跟一般的是相反的
        auto cmp1 = [](const pair<int,int>& l, const pair<int, int>& r) {return l.first > r.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp1)> cq(cmp1);

        // 按照profit排序
        auto cmp2 = [](const pair<int, int>& l, const pair<int, int>& r) {return l.second < r.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp2)> pq(cmp2);

        for (size_t i = 0; i < Profits.size(); ++i) {
            cq.push(pair<int, int>(Capital[i], Profits[i]));
        }

        while (k-- > 0) {
            while (!cq.empty() && W >= cq.top().first) {
                pq.push(cq.top());
                cq.pop();
            }
            if (pq.empty()) break;
            W += pq.top().second;
            pq.pop();
        }
        return W;

    }
};

int main(int argc, char *argv[]) {
    cout << "502.IPO" << endl;
    {
        Solution sol;
        vector<int> profits = {1, 2, 3};
        vector<int> capital = {0, 1, 1};
        cout << sol.findMaximizedCapital(2, 0, profits, capital) << endl;
    }
    return 0;
}