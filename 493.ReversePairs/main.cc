//
// Created by alexkkk on 2020/1/30.
//

#include <vector>
#include <deque>
#include "../util/dbg.h"

using namespace std;

using It = vector<int>::iterator;

class Solution {
 public:
  int SortAndCount(It begin, It end) {
    if (end - begin <= 1) return 0;
    auto mid = begin + (end - begin) / 2;
    int count = SortAndCount(begin, mid) + SortAndCount(mid, end);
    for (auto i = begin, j = mid; i != mid; ++i) {
      while (j != end and *i > 2L * *j) ++j;
      count += j - mid;
    }
    inplace_merge(begin, mid, end);
    return count;
  }
  int reversePairs(vector<int>& nums) {
    return SortAndCount(nums.begin(), nums.end());
  }
};

int main(int argc, char* argv[]) {
  Solution s;
//  vector<int> input = {1,3,2,3,1};
  vector<int> input = {233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004};
  dbg(s.reversePairs(input));
  return 0;
}