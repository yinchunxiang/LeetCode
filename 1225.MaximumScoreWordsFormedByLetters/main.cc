//
// Created by alexkkk on 2019/11/10.
//

#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
 public:

  bool UpdateLetterFreq(const string& word, vector<int>& freq) {
    for (auto c : word) {
      int index = c - 'a';
      freq[index] += 1;
      if (freq[index] > letter_count_[index]) return false;
    }
    return true;
  }


  void dfs(const vector<string>& words, int index, int score, vector<int> freq) {
    if (index >= words.size()) {
      max_score_ = max(max_score_, score);
      return;
    }

    taken_[index] = false;
    dfs(words, index + 1, score , freq);

    if (UpdateLetterFreq(words[index], freq)) {
      taken_[index] = true;
      dfs(words, index + 1, score + word_score_[words[index]], freq);
    }
  }


  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    taken_.resize(words.size(), false);
    for (auto& c : letters) {
      letter_count_[c - 'a'] += 1;
    }
    for (auto& word : words) {
      int word_score = 0;
      for (auto c : word) {
        word_score += score[c - 'a'];
      }
      word_score_.emplace(word, word_score);
    }

    vector<int> freq(26, 0);

    dfs(vector<string>& words, 0, freq);
    return max_score_;
  }


  vector<bool> taken_;
  vector<int> letter_count_= vector<int>(26, 0);
  unordered_map<string, int> word_score_;
  int max_score_ = 0;
};
