//
// Created by yinchunxiang on 15/11/2017.
//

#include <vector>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int low = 0;
        int high = nums.back() - nums.front();

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0, j = 0; i < nums.size(); ++i) {
                while (j < nums.size() && (mid >= nums[j] - nums[i])) {
                    ++j;
                }
                count += (j - 1 - i);
            }
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;

    }
};

