//
// Created by alexkkk on 2019-07-14.
//

#include <vector>

using namespace std;


int longestWPI(vector<int>& hours) {
  int N = hours.size();
  vector<int> td(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    td[i] = td[i - 1] + (hours[i - 1] > 8 ? 1 : 0);
  }

  for (int len = N; len >= 1; --len) {
    for (int i = 0; i + len < N; ++i) {
      int j = i + len - 1;
      auto tiring_days = td[j + 1] - td[i];
      if (tiring_days > len - tiring_days) {
        return len;
      }
    }
  }
}

int solve(vector<int>& hours) {
  int N = hours.size();
  // 这里存放的其实是：和为sum 对应的最小的 index
  unordered_map<int, int> sum_index_map;

  int max_len = 0;
  int sum = 0;
  for (int i = 1; i <= N; ++i) {
    int current = (hours[i - 1] > 8 ? 1 : -1);
    sum += current;
    if (sum_index_map.count(sum) < 1) {
      sum_index_map.emplace(sum, i);
    }
    // 计算以 i 结尾的interval 的最大长度
    if (sum > 0) {
      max_len = i + 1;
    } else {
      auto it = sum_index_map.find(sum - 1);
      if (sum_index_map.end() != it) {
        max_len = max(max_len, i - it->second);
      }
    }
  }
  return max_len;
}


int main(int argc, char* argv[]) {
  vector<int> input = {9,9,6,0,6,6,9};
  cout <<
  return 0;
}