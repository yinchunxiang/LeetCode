//
// Created by yinchunxiang on 27/11/2017.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (k * 3 >= n) {
            return {0, k, 2*k};
        }
        //@yincx: 这种初始化方式直接报异常了，要注意
        //vector<int> sum(0);
        // n + 1个元素, 第一个为0
        vector<int> sum = {0};
        for (auto i : nums) {
            sum.push_back(sum.back() + i);
        }
        //left[i]表示[0, i]范围内最大的index，初始化显然为0
        vector<int> left(n, 0);
        {
            for (int i = k, maxSum = sum[k] - sum[0]; i < n; ++i) {
                int total = sum[i + 1] - sum[i + 1 - k];
                if (total > maxSum) {
                    maxSum = total;
                    left[i] = i + 1 - k;
                } else {
                    left[i] = left[i - 1];
                }
            }
        }

        //right[i], 表示[i, n-1]范围内最大的index， 初始化显然为n-k
        vector<int> right(n, n - k);
        {
            for (int i = n - k - 1, maxSum = sum[n] - sum[n - k]; i >= 0; --i) {
                int total = sum[i + k] - sum[i];
                // 因为在左边，有顺序优势，所以等于的时候也要做替换
                if (total >= maxSum) {
                    maxSum = total;
                    right[i] = i;
                } else {
                    right[i] = right[i + 1];
                }
            }
        }


        int maxSum = 0;
        vector<int> result;
        // test all possible middle interval
        for (int i = k; i + 2 * k <= n; ++i) {
            int l = left[i - 1];
            int r = right[i + k];
            int total = sum[l + k] - sum[l] + sum[i + k] - sum[i] + sum[r + k] - sum[r];
            if (total > maxSum) {
                maxSum = total;
                result = {l, i, r};
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
    try {

        vector<int> input = {1,2,1,2,6,7,5,1};
        Solution s;
        auto result = s.maxSumOfThreeSubarrays(input, 2);
        for (auto i : result) {
            cout << i << endl;
        }
    } catch (exception e) {
        cout << e.what() << endl;
    }

    return 0;
}