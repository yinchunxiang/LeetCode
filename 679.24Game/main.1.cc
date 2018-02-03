//
// Created by yinchunxiang on 03/02/2018.
//

using namespace std;

#include <vector>
#include <unordered_set>
#include <iostream>


class Solution {
public:
    bool dfs(int count, const vector<int>& nums, unordered_set<int> used, double sum) {
        if (count >= nums.size()) {
            return abs(sum - 24.0) < 0.01;
        }
        for (int i = 0; i < nums.size(); ++i) {
            auto it = used.find(i);
            if (it != used.end()) continue;

            {// +
                unordered_set<int> nextUsed(used);
                nextUsed.insert(i);
                if (dfs(count + 1, nums, nextUsed, sum + nums[i])) {
                    return true;
                }
            }
            {// -
                unordered_set<int> nextUsed(used);
                nextUsed.insert(i);
                if (dfs(count + 1, nums, nextUsed, sum - nums[i])) {
                    return true;
                }
            }
            {// *
                unordered_set<int> nextUsed(used);
                nextUsed.insert(i);
                if (dfs(count + 1, nums, nextUsed, sum * nums[i])) {
                    return true;
                }
            }
            {// /
                if (0 != nums[i]) {
                    unordered_set<int> nextUsed(used);
                    nextUsed.insert(i);
                    if (dfs(count + 1, nums, nextUsed, sum / (double)nums[i])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        return dfs(0, nums, {}, 0.0);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {4, 1, 8, 7};
        cout << s.judgePoint24(input) << endl;
    }
    {
        vector<int> input = {1, 2, 1, 2};
        cout << s.judgePoint24(input) << endl;
    }
    {
        vector<int> input = {1, 4, 6, 1};
        cout << s.judgePoint24(input) << endl;
    }
    return 0;
}
