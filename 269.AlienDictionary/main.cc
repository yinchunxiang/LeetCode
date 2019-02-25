#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


using namespace std;


class Solution {
    public:
        string alienOrder(vector<string>& words) {
          if (words.empty()) return "";
          unordered_map<char, int> indegree;
          for (const auto& word : words) {
            for (const auto& c : word) {
              indegree[c] = 0;
            }
          }

          unordered_map<char, unordered_set<char>> next;
          int n = words.size();
          for (int i = 0; i < n - 1; ++i) {
            int len = std::min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < len; ++j) {
              const auto& a = words[i][j];
              const auto& b = words[i + 1][j];
              if (a == b) continue;
              auto& s = next[a];
              auto it = s.find(b);
              if (it == s.end()) {
                s.insert(b);
                indegree[b] += 1;
              }
              break;
            }
          }

          for (const auto& p : indegree) {
            cout << p.first << " => " << p.second << endl;
          }

          unordered_set<char> current_level;
          for (const auto& p : indegree) {
            if (p.second > 0) continue;
            current_level.insert(p.first);
          }

          unordered_set<char> next_level;
          string result;
          while (!current_level.empty()) {
            for (const auto& c : current_level) {
              result += c;
              auto it = next.find(c);
              if (it == next.end()) continue;
              for (const auto& c : it->second) {
                indegree[c] -= 1;
                if (0 == indegree[c]) {
                  next_level.insert(c);
                }
              }
            }
            current_level.swap(next_level);
            next_level.clear();
          }

          // 可能有indegree = 0， 或者部分循环导致结果字符串多了， 比如[a, x, y, x]
          if (result.size() != indegree.size()) {
            return "";
          }
          return result;

        }

};




int main(int argc, char* argv[]) {
  Solution s;
  {
    vector<string> input = {  "wrt",
                              "wrf",
                              "er",
                              "ett",
                              "rftt"};
    cout << s.alienOrder(input) << endl;
  }
  return 0;
}
