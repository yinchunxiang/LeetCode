//
// Created by alexkkk on 2019/12/22.
//

#include <unordered_map>
#include <vector>
#include <map>
#include <iostream>
#include <numeric>
#include <numeric>

#include "../util/dbg.h"

using namespace std;


class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    if (points.size() < 3) return points.size();

    int res = 0;
    // 遍历 points
    for (int i = 0; i < points.size(); ++i) {
      int dup = 0;
//      std::unordered_map<std::pair<int, int>, int> slopes;
      std::map<std::pair<int, int>, int> slopes;
      auto& p1 = points[i];
      for (int j = 0; j < points.size(); ++j) {
        auto p2 = points[j];

        int dx = p2[0] - p1[0];
        int dy = p2[1] - p1[1];

        if (dx == 0 && dy == 0) {
          dup += 1;
          continue;
        }
        // 考虑正向和反向, 所以需要 abs
        int d = abs(__gcd(dy, dx));
        slopes[{dx/d, dy/d}] += 1;
      }
      dbg(p1);
      dbg(slopes);
      // 只有重复节点的情况
      res = max(res, dup);
      for (auto slope : slopes) {
        res = max(res, slope.second + dup);
      }
    }
    // 加上节点本身
    return res ;
  }
};

int main(int argc, char* argv[]) {
  std::vector<vector<int>> points = {
      {1,1}, {3,2}, {5,3},{4,1},{2,3},{1,4}
  };
  Solution s;
  std::cout << s.maxPoints(points) << std::endl;
  return 0;
}

