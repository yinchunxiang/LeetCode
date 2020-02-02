//
// Created by alexkkk on 2020/1/27.
//

#include <vector>
#include <deque>
#include <iostream>
#include "../util/dbg.h"

using namespace std;

int sumSubarrayMins(vector<int>& A) {
  int result = 0;
  int n = A.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int step = 1; step <= n; ++step) {
    for (int i = 0; i + step - 1 < n; ++i) {
      int j = i + step - 1;
      if (i == j) {
        dp[i][j] = A[i];
      } else if (i + 1 == j) {
        dp[i][j] = min(A[i], A[j]);

      } else {
        dp[i][j] = min(dp[i][i], dp[i + 1][j]);
      }
      result += dp[i][j];
      result %= 100000007;
      dbg(dp);
    }
  }
  return result;
}

int sumsub(vector<int>& A) {
  int result = 0;
  int n = A.size();
  for (int k = 1; k <= n; ++k) {
    deque<int> d;
    for (int i = 0; i < n; ++i) {
      while (!d.empty() && i - d.front() > k - 1) {
        d.pop_front();
      }
      while (!d.empty() && A[d.back()] > A[i]) {
        d.pop_back();
      }
      d.push_back(i);
      if (i >= k - 1) {
        result += A[d.front()];
        result %= 100000007;
      }
    }
  }
  return result;
}

int ss(vector<int>& A) {
  int n = A.size();

  // 到上一个左边比他小的元素的距离
  vector<int> left(n);
  for (int i = 0; i < n; ++i) left[i] = i + 1;


  // left -> right 单调递增队列, 因为要知道前一个比当前小的
  {
    deque<int> d;
    for (int i = 0; i < n; ++i) {
      while (!d.empty() && A[d.back()] >= A[i]) d.pop_back();
      left[i] = d.empty() ? i + 1 : i - d.back() ;
      d.push_back(i);
    }
    dbg(left);
  }


  // 到上一个右边比他小的元素的距离
  vector<int> right(n);
  for (int i = 0; i < n; ++i) right[i] = n - i;
  // right->left 单调递增队列, 因为要知道后一个比当前小的
  {
    deque<int> d;
    for (int i = n - 1; i >= 0; --i) {
      while (!d.empty() && A[d.back()] >= A[i]) d.pop_back();
      right[i] = d.empty() ? n - i : d.back() - i;
      d.push_back(i);
    }
    dbg(right);
  }

  long result = 0;
  for (int i = 0; i < n; ++i) {
    dbg(result);
    result += A[i] * (left[i] ) * (right[i] );
    result %= 1000000007;
  }

  return result;
}


int main(int argc, char* argv[]) {
  vector<int> input {3, 1, 2, 4};
  dbg(sumSubarrayMins(input));
  dbg(sumsub(input));
  dbg(ss(input));
  return 0;
}

