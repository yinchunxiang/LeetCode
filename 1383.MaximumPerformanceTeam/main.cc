//
// Created by alexkkk on 2020/3/22.
//

#include "../util/dbg.h"

/** 跟 857.MinimuxCostToHireKWorkers 基本思路一样
 *
1383. Maximum Performance of a Team
There are n engineers numbered from 1 to n and two arrays: speed and efficiency,
 where speed[i] and efficiency[i] represent the speed and efficiency for the i-th engineer respectively.
 Return the maximum performance of a team composed of at most k engineers,
 since the answer can be a huge number, return this modulo 10^9 + 7.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.



Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation:
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4)
 and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
Example 2:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
Output: 68
Explanation:
This is the same example as the first but k = 3. We can select engineer 1,
 engineer 2 and engineer 5 to get the maximum performance of the team.
 That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
Example 3:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
Output: 72


Constraints:

1 <= n <= 10^5
speed.length == n
efficiency.length == n
1 <= speed[i] <= 10^5
1 <= efficiency[i] <= 10^8
1 <= k <= n
*/


int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
  vector<pair<int, int>> eff_sp;
  priority_queue <int, vector<int>, greater<int> > pq_speeds;
  long sum = 0, res = 0;
  for (auto i = 0; i < n; ++i) {
    eff_sp.push_back({efficiency[i], speed[i]});
  }
  // 按照 efficiency 排序
  sort(begin(eff_sp), end(eff_sp));
  for (auto i = n - 1; i >= 0; --i) {
    // speed 求和
    sum += eff_sp[i].second;
    pq_speeds.push(eff_sp[i].second);
    // 替换出 speed 最小的
    if (pq_speeds.size() > k) {
      sum -= pq_speeds.top();
      pq_speeds.pop();
    }
    res = max(res, sum * eff_sp[i].first);
  }
  return res % 1000000007;
}

class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    int N = speed.size();
    priority_queue<pair<int, int>>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;
    for (int i = 0; i < N; ++i) {
      if (i < k) {
        q.emplace_back(speed[i], efficiency[i]);
      } else {

      }
    }
  }
};

int main(int argc, char* argv[]) {

  return 0;
}
