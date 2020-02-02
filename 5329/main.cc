//
// Created by alexkkk on 2020/2/2.
//

#include <vector>
#include <map>
#include <unordered_map>
#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    std::multimap<int, int, std::greater<int>> m;
    std::unordered_map<int, int> count;
    for (auto n : arr) {
      count[n] += 1;
    }
    for (auto& p : count) {
      m.emplace(p.second, p.first);
    }
    int value = (arr.size() - 1) / 2 + 1;
    int cnt = 0;
    int sum = 0;
    for (auto& p : m) {
      cnt += 1;
      sum += p.first;
      if (sum >= value) break;
    }
    return cnt;
  }
};

int main(int argc, char* argv[]) {
  vector<int> input = {1,2,3,4,5,6,7,8,9,10};
  Solution s;
  dbg(s.minSetSize(input));

  return 0;
}

