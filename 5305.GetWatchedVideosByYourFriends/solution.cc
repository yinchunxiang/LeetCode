//
// Created by alexkkk on 2020/1/5.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

#include "../util/dbg.h"

using namespace std;

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& v) {
  out << "{" << v.first << "," << v.second << "}";
  return out;
}

class Solution {
 public:
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                        vector<vector<int>>& friends, int id, int level) {
    unordered_set<int> f;
    unordered_set<int> current = {id};
    unordered_set<int> used = {id};
    bfs(0, level, friends, current, used);
    unordered_map<string, int> count;
    for (auto id : current) {
      auto& videos= watchedVideos[id];
      for (auto& v : videos) {
        count[v] += 1;
      }
    }
    vector<std::pair<string, int>> v(count.begin(), count.end());
    auto cmp = [](const std::pair<string, int>& l, const std::pair<std::string, int>& r) {
      if (l.second < r.second) return true;
      if (l.second > r.second) return false;
      return l.first < r.first;
    };
    std::sort(v.begin(), v.end(), cmp);
    std::vector<std::string> result;
    for (auto& p : v) {
      result.push_back(p.first);
    }

    return result;
  }

  void bfs(int level, int target_level,
           vector<vector<int>>& friends,
           unordered_set<int>& current,
           unordered_set<int>& used) {
    if (level == target_level) {
      return;
    }
    unordered_set<int> next;
    for (auto id : current) {
      auto& ids = friends[id];
      for (auto fid : ids) {
        if (used.count(fid) > 0) continue;
        next.insert(fid);
      }
    }
    dbg(used);
    dbg(next);
    used.insert(next.begin(), next.end());
    dbg(used);
    swap(current, next);
    bfs(level + 1, target_level, friends, current, used);
  }


};

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<string>> watchedVideos = {
      {"A","B"},
      {"C"},
      {"B","C"},
      {"D"}
  };
  vector<vector<int>> friends = {
      {1,2},{0,3},{0,3},{1,2}
  };

  dbg(s.watchedVideosByFriends(watchedVideos, friends, 0, 2));
  return 0;
}
