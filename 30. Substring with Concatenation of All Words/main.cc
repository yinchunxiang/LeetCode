//
// Created by alexkkk on 2020/2/5.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int size = words[0].size();
    unordered_map<string, int> target;
    for (auto& word : words) {
      target[word] += 1;
    }
    unordered_map<string, int> t;
    int start = 0;
    int end = 0;
    int N = s.size() / size ;
    int count = 0;
    vector<int> result;
    while (end < N) {
      dbg(result);
      dbg(t);
      auto word = s.substr(end++ * size, size);
      if (++ t[word] <= target[word]) count += 1;
      while (t[word] > target[word]) {
        auto w = s.substr(start++ * size, size);
        if (t[w]-- <= target[w]) count -= 1;

      }
      if (count == words.size()) {
        result.push_back(start * size);
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  vector<string> words {"fooo","barr","wing","ding","wing"};
  dbg(solution.findSubstring(s, words));

  return 0;
}
