//
// Created by alexkkk on 2/1/18.
//

using namespace std;

#include <vector>
#include <numeric>

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto lb = *max_element(begin(nums), end(nums));
        auto ub = accumulate(begin(nums), end(nums), 0);
        while (lb < ub) {
            int mid = lb + (ub - lb) / 2;
            if (isValidSplit(nums, m, mid)) {
                ub = mid;
            } else {
                lb = mid + 1;
            }
        }
        return lb;
    }
    bool isValidSplit(vector<int> &nums, int m, int sum) {
        int count = 1;
        int currSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > sum) return false;
            currSum += nums[i];
            if (currSum > sum) {
                currSum = nums[i];
                count += 1;
                if (count >= m) return false;
            }
        }
        return count <= m;

    }

};
