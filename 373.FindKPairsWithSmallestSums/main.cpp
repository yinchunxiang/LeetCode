//
// Created by yinchunxiang on 15/11/2017.
//

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result;
        }
        auto comp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);

        while (k-- > 0 && !min_heap.empty()) {
            auto idx_pair = min_heap.top();
            min_heap.pop();
            int index1 = idx_pair.first;
            int index2 = idx_pair.second;
            result.emplace_back(nums1[index1], nums2[index2]);
            // nums1的下标一直增加
            if (index1 + 1 < nums1.size()) {
                min_heap.emplace(index1 + 1, index2);
            }

            // nums2的下标
            if (0 == index1 && index2 + 1 < nums2.size()) {
                min_heap.emplace(index1, index2 + 1);
            }
        }
        return result;
    }
};
