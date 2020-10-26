//
// Created by alexkkk on 2020/4/26.
//


#include <iostream>
#include <vector>
#include "../util/dbg.h"

using namespace std;



class Solution {
 public:
  using It = vector<int>::iterator;
  int maxScore(vector<int>& cardPoints, int k) {
    return max_score(cardPoints.begin(), cardPoints.end(), k);
  }
  int max_score(It begin, It end, int k) {
    if (k == 0) return 0;
    if (begin == end) return 0;
    if (begin + 1 == end) return *begin;
    int left = *begin + max_score(begin + 1, end, k - 1);
    int right = *(end - 1) + max_score(begin, end - 1, k  - 1);
    int result = max(left, right);
    dbg(k);
    dbg(vector<int>(begin, end));
    dbg(result);
    return result;
  }

  int maxScoreV1(vector<int>& cardPoints, int k) {
    int N = cardPoints.size();
    vector<int> left(N, 0);
    left[0] = cardPoints[0];
    for (int i = 1; i < N; ++i) {
      left[i] = left[i - 1] + cardPoints[i];
    }
    vector<int> right(N, 0);
    right[N - 1] = cardPoints[N - 1];
    for (int i = N - 2; i >= 0; --i) {
      right[i] = cardPoints[i] + right[i + 1];
    }
    int result = 0;
    for (int i = 0; i <=k; ++i) {
      if (i == 0) {
        result = max(result, right[N - k]);
        continue;
      }
      if (i == k) {
        result = max(result, left[k - 1]);
        continue;
      }
      result = max(result, left[i - 1] + right[N - 1 - k + i]);
    }
    return result;

  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input = {1, 2, 3, 4, 5, 6, 1};

  dbg(s.maxScore(input, 3));;

  return 0;
}

