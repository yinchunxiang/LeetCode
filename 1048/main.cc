#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    unordered_map<int, unordered_set<string>> dict;
    unordered_map<string, int> word_chain_count;
    int max_len = 0;
    for(auto word : words) {
      sort(word.begin(), word.end());
      dict[word.size()].insert(word);
      max_len = max(max_len, (int)word.size());
      word_chain_count[word] = 1;

    }
    int max_chain_len = 1;
    for (int i = max_len - 1; i >= 1; --i) {
      if (dict[i + 1].size() <= 0) continue;
      for (auto word : dict[i]) {
        for (int j = 0; j < 26; ++j) {
          char c = 'a' + j;
          auto new_word = word + c;
          sort(new_word.begin(), new_word.end());
          word_chain_count[word] = max(word_chain_count[word],
                                       1 + word_chain_count[new_word]);
          max_chain_len = max(max_chain_len, word_chain_count[word]);
          cout << "word: " << word << " new_word:" << new_word
               <<  " " << word_chain_count[word] << endl;
        }

      }
    }
    return max_chain_len;

  }


};

int main(int argc, const char *argv[]) {
  Solution s;
  vector<string> words {"a","b","ba","bca","bda","bdca"};
  cout << s.longestStrChain(words) << endl;
  return 0;
}

