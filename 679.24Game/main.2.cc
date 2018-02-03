//
// Created by yinchunxiang on 03/02/2018.
//

using namespace std;

#include <vector>
#include <unordered_set>
#include <iostream>


class Solution {
public:
    static const double diff = 0.000001;

    bool judge(vector<int> nums, double target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                vector<int> rest;
                for (int k = 0; k < nums.size(); ++k) {
                    if (i == k || j == k) continue;
                    rest.push_back(nums[k]);
                }

                // +
                if (judge2(rest[0], rest[1], target - (nums[i] + nums[j]))) {
                    return true;
                }

                // *
                if (judge2(rest[0], rest[1], target - (nums[i] + nums[j]))) {
                    return true;
                }

            }
        }

    }
    bool judge2(int l, int r, double target) {
        // l + r == target
        if (abs(l + r - target) < diff) return true;
        // (l - r) == target 或者 (r - l) == target
        if (abs(target - abs(l - r)) < diff) return true;
        // l * r == target
        if (abs(l * r - target) < diff) return true;
        // l / r == target 或者 r / l == target
        if (0 != r && abs(l/r - target) < diff) return true;
        if (0 != l && abs(r/l - target) < diff) return true;
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        double target = 24.0;
        return judge(nums, target);
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
    {
        vector<int> input = {1, 9, 1, 2};
        cout << s.judgePoint24(input) << endl;
    }
    return 0;
}
