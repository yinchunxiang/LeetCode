//
// Created by alexkkk on 2020/2/2.
//

#include <vector>
#include <iostream>

#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    int N = arr.size();
    vector<int> left(N, -1);
    {
      vector<int> v {0};
      for (int i = 1; i < N; ++i) {
        while (!v.empty() && arr[v.back()] < arr[i]) v.pop_back();
        left[i] = v.empty() ? -1 : v.back();
        v.push_back(i);
      }
      dbg(left);
    }
    vector<int> right(N, N);
    {
      vector<int> v {N - 1};
      for (int i = N - 2; i >= 0; --i) {
        while (!v.empty() && arr[v.back()] < arr[i]) v.pop_back();
        right[i] = v.empty() ? N : v.back();
        v.push_back(i);
      }
      dbg(right);
    }
    vector<int> index;
    for (int i = 0; i < N; ++i) {
      index.push_back(i);
    }
    auto comp = [&arr](int i, int j) {
      return arr[i] < arr[j];
    };
    sort(index.begin(), index.end(), comp);
    dbg(index);
    vector<int> dp(N, 1);
    for (auto i : index) {

      int l = left[i];
      for(int j = max(l + 1, i - d); j < i; ++j) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      int r = right[i];
      for (int j = i + 1; j < min(r, i + d + 1); ++j) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    int result = 1;
    for (auto c : dp) {
      if (c > result) result = c;
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input = {6,4,14,6,8,13,9,7,10,6,12};
  dbg(s.maxJumps(input, 2));
  return 0;
}
