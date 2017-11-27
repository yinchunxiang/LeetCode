//
// Created by yinchunxiang on 26/11/2017.
//

#include <vector>
#include <queue>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
private:
    int sum_ = 0;
    vector<int> result_;
public:


    int getPathSum(vector<int>& nums, vector<int>& path, int k) {
        int result = 0;
        for (auto& index : path) {
            int sum = std::accumulate(
                    next(begin(nums), index), next(begin(nums), index + k), 0
            );
            result += sum;
        }
        return result;
    }

    void dfs(vector<int>& nums, int index, int k, int level, vector<int> path) {
        if (3 == level) {
            for (auto index : path) {
                cout << index << ", ";
            }
            cout << endl;
            int pathSum = getPathSum(nums, path, k);
            cout << "---> sum: " << pathSum << endl;
            if (pathSum > sum_) {
                sum_ = pathSum;
                result_.swap(path);
            }
            return;
        }
        if ((index + k * (3 - level)) > nums.size()) {
            return;
        }
        for (int i = 0; i + index + k * (3 - level) <= nums.size();  ++i) {
            path.push_back(i + index);
            dfs(nums, index + i + k, k, level + 1, path);
            path.pop_back();
        }
        return;

    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k * 3 >= n) {
            return {0, k, 2*k};
        }
        dfs(nums, 0, k, 0, {});
        return result_;
    }
};

int main(int argc, char *argv[]) {
    vector<int> input = {1,2,1,2,6,7,5,1};
    Solution s;
    auto result = s.maxSumOfThreeSubarrays(input, 2);
    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}

