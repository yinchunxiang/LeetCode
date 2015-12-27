#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    size_t size = nums.size();
    if (0 == size) return 0;
    int cur_min = nums[0];
    int cur_max = nums[0];
    int res = nums[0];
    cout << "cur_min:" << cur_min << " cur_max:" << cur_max << " res:" << res << endl;
    for (int i = 1; i < size; ++i) {
        int temp = cur_min;
        cur_min = std::min(nums[i], std::min(nums[i] * cur_min, nums[i] * cur_max));
        cur_max = std::max(nums[i], std::max(nums[i] * temp, nums[i] * cur_max));
        res = std::max(cur_max, res);
        cout << "cur_min:" << cur_min << " cur_max:" << cur_max << " res:" << res << endl;
    }
    return res;
}


int main(int argc, const char *argv[])
{
    vector<int> input{-3, -4};
    cout << maxProduct(input) << endl;

    return 0;
}

