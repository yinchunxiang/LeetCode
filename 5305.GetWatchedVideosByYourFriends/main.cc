//
// Created by alexkkk on 2020/1/5.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>

using namespace std;

vector<string> watchedVideoByFriends(vector<vector<string>>& watchedVideos,
    vector<vector<int>>& friends, int id, int level) {
  unordered_set<int> visited = {id};
  vector<int> current = {id};

  vector<string> res;

  while (level-- > 0) {
    vector<int> next;
    for (auto id : current) {
      for (auto friend_id : friends[id]) {
        if (visited.insert(friend_id).second) next.push_back(friend_id);
      }
    }
    swap(current, next);
  }
  unordered_map<string, int> freq;
  for (auto id : current) {
    for (auto& vid : watchedVideos[id]) {
      freq[vid] += 1;
    }
  }
  std::multiset<std::pair<int, string>> s;
  for (auto& p : freq) {
    s.emplace(p.second, p.first);
  }
  for (auto& p : s) {
    res.push_back(p.second);
  }
  return res;
}