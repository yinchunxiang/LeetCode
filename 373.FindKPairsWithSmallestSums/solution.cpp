//
// Created by alexkkk on 11/16/17.
//

#include <vector>
#include <queue>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return result;
        }

        struct Tuple {
            int x_;
            int y_;
            int val_;

            Tuple(int x, int y, int val) : x_(x), y_(y), val_(val) {
            }

            //@yincx: 实现operator > 要有最后的const
            bool operator > (const Tuple other) const{
                return val_ > other.val_;
            }
        };

        priority_queue<Tuple, std::vector<Tuple>, std::greater<Tuple>> min_heap;

        int m = (int)nums1.size();
        int n = (int)nums2.size();

        for (int i = 0; i < min(k, m); ++i) {
            min_heap.emplace(i, 0, nums1[i] + nums2[0]);
        }

        for (int i = 0; i < min(k, m * n); ++i) {
            auto t = min_heap.top(); min_heap.pop();
            result.emplace_back(nums1[t.x_], nums2[t.y_]);
            if (t.y_ == nums2.size() - 1) continue;
            min_heap.emplace(t.x_, t.y_ + 1, nums1[t.x_] + nums2[t.y_ + 1]);
        }

        return result;

    }
};

int main(int argc, char* argv[]) {
    //TODO
    {
        vector<int> nums1 = {1, 1, 2};
        vector<int> nums2 = {1, 2, 3};
        Solution s;
        auto result = s.kSmallestPairs(nums1, nums2, 10);
        for (auto p : result) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }

    }
    cout << "------------------------------------------" << endl;
    {
        vector<int> nums1 = {1};
        vector<int> nums2 = {3, 5, 6, 7, 8, 100};
        Solution s;
        auto result = s.kSmallestPairs(nums1, nums2, 4);
        for (auto p : result) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }

    }

    return 0;
}

