#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    size_t size = nums.size();
    if (0 == size) return 0;
    vector<int> dp = nums;
    int max = dp[0];
    for (int i = 1; i < size; ++i) {
        if (dp[i - 1] > 0) {
            dp[i] += dp[i - 1];
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}



int main(int argc, const char *argv[])
{

    vector<int> input{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(input) << endl;
    return 0;
}

