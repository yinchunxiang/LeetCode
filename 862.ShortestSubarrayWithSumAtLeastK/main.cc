//
// Created by alexkkk on 2020/1/26.
//

#include <vector>
#include <deque>

using namespace std;

class Solution {
 public:
  int shortestSubarray(vector<int>& A, int K) {
    int n = A.size();
    int res = n + 1;
    deque<int> d;

    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        A[i] += A[i - 1];
      }
      if (A[i] >= K) {
        res = min(res, i + 1);
      }
      while (d.size() > 0 && A[i] - A[d.front()] >= K) {
        res = min(res, i - d.front());
        d.pop_front();
      }
      while (d.size() > 0 && A[i] <= A[d.back()]) {
        d.pop_back();
      }
      d.push_back(i);
    }

  }

  int ss(vector<int>& A, int K) {
    vector<int> prefix{0};
    int n = A.size();
    for (int i = 0; i < n; ++i) {
      prefix.push_back(A[i] + prefix.back());
    }
    int res = A.size() + 1;
    int start = 0;
    for(int end = 0; end < A.size();) {
      if (start == 0) {
        if (prefix[end] < K) {
          end ++;
          continue;
        }
        res = min(res, end + 1);
        start += 1;
        int sum = A[start]
        // 找到下一个可以的start
        while (sum < 0) {
          start += 1;
          sum += A[start];
        }

      } else {
        if (prefix[end] - prefix[start - 1] < K) {
          end ++;
          continue;
        }
        res = min(res, end - start + 1);
        start += 1;
        int sum = A[start]
        // 找到下一个可以的start
        while (sum < 0) {
          start += 1;
          sum += A[start];
        }

      }
    }
    return res == A.size() + 1 ? 0 : res;

  }

  /**
   * Time Complexity: O(n)
   * Space Complexity: O(n)
   */
  int shortest_subarray(vector<int>& A, int K) {
    int n = A.size();
    int res = n + 1;
    for (int i = 1; i < n; ++i) {
      A[i] += A[i - 1];
    }
    deque<int> d;

    for (int i = 0; i < n; ++i) {
      // 为什么要有这个？ 相当于保证在d为空的情况下，每个都会得到pop的机会
      if (A[i] >= K) res = min(res, i + 1);
      while (!d.empty() && A[i] - A[d.front()] >= K) {
        res = min(res, i - d.front());
        d.pop_front();
      }
      // 维护单调递增队列
      while (!d.empty() && A[d.back()] >= A[i]) {
        d.pop_back();
      }
      d.push_back(i);
    }
    return res <= n ? res : -1;


  }



};