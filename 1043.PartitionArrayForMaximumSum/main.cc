//
// Created by alexkkk on 2019-05-12.
//

/**
1043. Partition Array for Maximum Sum
User Accepted: 556
User Tried: 806
Total Accepted: 562
Total Submissions: 1276
Difficulty: Medium
Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.
 After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.



Example 1:

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]


Note:

1 <= K <= A.length <= 500
0 <= A[i] <= 10^6
 */


#include <vector>
#include <queue>
#include <numeric>

#include <iostream>

using namespace std;


/**
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& A, int K) {
    if (0 == K) return 0;
    if (1 == K) return accumulate(A.begin(), A.end(), 0);
    vector<int> dp(A.size() + 1, 0);
    for (int i = 0; i < A.size(); ++i) {
      int kmax = A[i];
      for (int count = 0; count < K; ++count) {
        int j = i - count;
        if (j < 0) break;
        kmax = max(kmax, A[j]);
        int size = count + 1;
        cout << "kmax: " << kmax << " size:" << size << endl;
        dp[i + 1] = max(dp[i + 1], dp[j] + kmax * size);
      }
      cout << "---> dp[" << i + 1 << "]: " << dp[i + 1] << endl;
    }
    return dp[A.size()];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input = {1, 15, 7, 9, 2, 5, 10};
  std::cout << s.maxSumAfterPartitioning(input, 3) << std::endl;
  return 0;
}