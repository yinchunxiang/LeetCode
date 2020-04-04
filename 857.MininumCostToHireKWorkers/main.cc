//
// Created by alexkkk on 2020/3/22.
//

#include <vector>
#include <queue>
#include <limits>

#include "../util/dbg.h"

using namespace std;


class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    // per_quality, quality
    vector<std::pair<float, int>> v;
    for (int i = 0; i < wage.size(); ++i) {
      v.emplace_back(1.0 * wage[i] / quality[i], quality[i]);
    }
    sort(v.begin(), v.end());
    dbg(v);
    priority_queue<int, vector<int>, less<int>> q;
    int qsum = 0;
    double result = std::numeric_limits<double>::max();
    for (int i = 0; i < v.size(); ++i) {
      double per_quality = v[i].first;
      if (q.size() >= K) {
        qsum -= q.top();
        q.pop();
      }
      qsum += v[i].second;
      q.push(v[i].second);
      if (q.size() >= K) {
        auto current = 1.0 * per_quality * qsum;
        dbg(1.0f * per_quality * qsum);
        result = std::min(result, current);
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> quality = {3,1,10,10,1};
  vector<int> wage = {4, 8, 2, 2, 7};
  dbg(s.mincostToHireWorkers(quality, wage, 3));
  return 0;
}

