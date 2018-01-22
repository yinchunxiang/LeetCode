//
// Created by alexkkk on 1/17/18.
//

#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    typedef vector<int>::iterator IntVecIter;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        struct Comp {
            bool operator() (const pair<IntVecIter, IntVecIter> &a, const pair<IntVecIter, IntVecIter> &b) {
                return *a.first > *b.first;
            }
        };
        priority_queue<pair<IntVecIter, IntVecIter>, vector<pair<IntVecIter, IntVecIter>>, Comp> heap;
        int left = INT_MAX;
        int right = INT_MIN;
        for (const auto& numList : nums) {
            left = min(left, numList[0]);
            right = max(right, numList[0]);
            heap.emplace(numList.begin(), numList.end());
        }
        while (true) {
            auto p = move(heap.top());
            heap.pop();
            if (++p.first == p.second) break;
            heap.push(p);
            int curLeft = *heap.top().first;
            int curRight = max(right, *p.first);
            if (curRight - curLeft < right - left)  {
                left = curLeft;
                right = curRight;
            }
        }
        return {left, right};
    }
};