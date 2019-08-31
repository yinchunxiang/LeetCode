//
// Created by alexkkk on 2019-07-14.
//

#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>

#include "../util/base.h"

using namespace std;


class Solution {
public:
  vector<int> smallestSufficientTeam(vector <string> &req_skills, vector <vector<string>> &people) {
    unordered_set<string> skills(req_skills.begin(), req_skills.end());
    unordered_set<int> used_people;
    vector<int> result;
    while (!skills.empty()) {
      cout << "--> skills:";
      prints(skills);

      int count = 0;
      int index = -1;
      for (int i = 0; i < people.size(); ++i) {
        if (used_people.count(i) > 0) continue;
        int num_skills = 0;
        for (const auto& skill : people[i]) {
          if (skills.count(skill) > 0) {
            num_skills += 1;
          }
        }
        if (num_skills > count) {
          count = num_skills;
          index = i;
        }
      }
      cout << "index: " << index << endl;

      result.push_back(index);
      used_people.insert(index);
      for (const auto& skill : people[index]) {
        skills.erase(skill);
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<string> req_skills {"java","nodejs","reactjs"};
  vector<vector<string>> people {
      {"java"},{"nodejs"},{"nodejs","reactjs"}
  };
  Solution s;
  auto result = s.smallestSufficientTeam(req_skills, people);
  printv(result);

  return 0;
}
