//
// Created by alexkkk on 2019-07-14.
//

#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
#include <unordered_map>
#include <bitset>

#include "../util/base.h"

using namespace std;


class Solution {
public:
  vector<int> smallestSufficientTeam(vector <string> &req_skills, vector <vector<string>> &people) {
    int m = people.size();
    int n = 1<<req_skills.size();

    vector<int> result;

    // 将技能转换成下标
    unordered_map<string,int> skill_map;
    for(int i = 0; i < req_skills.size(); i++) {
      skill_map[req_skills[i]]=i;
    }

    // 这么写内存超了，换乘滚动数组
    vector<vector<int>> dp(n, vector<int>());
    for (int i = 1; i < n; ++i) {
      for (int k = 0; k < m; ++k) {
        dp[i].push_back(k);
      }
    }

    for (int i = 1; i <= m; ++i) {
      int skills = 0;
      for(const auto& skill : people[i - 1]) {
        skills |= 1<<skill_map[skill];
      }
      for (int j = 1; j < n; ++j) {
        // 不需要people[i]的技能集合
        if (dp[j].size() < m) continue;
        auto dp1 = dp[j];
        // 需要people[i]的技能集合
        int mask = 0xffff ^ skills;
        auto sub = j & mask;
        auto dp2 = dp[sub];
        if (dp1.size() < dp2.size() + 1) {
          dp[j].swap(dp1);
        } else {
          dp[j].swap(dp2);
          dp[j].push_back(i - 1);
        }

      }
    }
    return dp[n - 1];
  }
};

int main(int argc, char* argv[]) {
  vector<string> req_skills {"java","nodejs","reactjs"};
//  vector<string> req_skills {"algorithms","math","java","reactjs","csharp","aws"};
  printv(req_skills);

  vector<vector<string>> people {
      {"java"},{"nodejs"},{"nodejs","reactjs"}
//      {"algorithms","math","java"},
//      {"algorithms","math","reactjs"},
//      {"java","csharp","aws"},
//      {"reactjs","csharp"},
//      {"csharp","math"},
//      {"aws","java"}
  };
  printvv(people);
  Solution s;
  auto result = s.smallestSufficientTeam(req_skills, people);
  printv(result);

  return 0;
}
