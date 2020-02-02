//
// Created by alexkkk on 2019/12/29.
//

#include "../util/dbg.h"

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <string>


//using namespace std;

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& v) {
  out << "{" << v.first << "," << v.second << "}";
  return out;
}

class Solution {
 public:

  int WordToInt(std::string& word, std::unordered_map<char, int>& char_int_map) {
    int result = 0;
    for (auto c : word) {
      result = 10 * result + char_int_map[c];
    }
    return result;
  }

  bool check(std::vector<std::string>& words, std::string& result,
             std::unordered_map<char,int>& char_int_map) {
    std::cout << "--->run check" << std::endl;
    if (char_int_map[result[0]] == 0) {
      std::cout << "--> exit 111" << std::endl;
      return false;
    }
    for (auto& word : words) {
      if (char_int_map[word[0]] == 0) {

        std::cout << "--> exit 2222" << std::endl;
        return false;
      }
    }
    int left = 0;
    for (auto& word : words) {
      left += WordToInt(word, char_int_map);
    }
    if(left == WordToInt(result, char_int_map))  {

      for (auto& p : char_int_map) {
        std::cout << p.first << " => " << p.second << std::endl;
      }
      std::cout << "left:" << left << " right:" << WordToInt(result, char_int_map) << std::endl;
      return true;
    }
    std::cout << "--> exit 333" << std::endl;
    return false;
  }

  bool solve(std::vector<std::string>& words,
             std::string& result,
             std::unordered_set<char>& charset,
             std::unordered_map<char, int>& char_int_map,
             std::vector<bool>& used) {
    if (char_int_map.size() >= charset.size()) {
      dbg(used);
      dbg(char_int_map);
      auto res = check(words, result, char_int_map);
      dbg(res);
      return res;
    }
    for (auto c : charset) {
      if (char_int_map.count(c)) continue;
      for (int i = 0; i < 10; ++i) {
        if (used[i]) continue;
        char_int_map[c] = i;
        used[i] = true;
        if (solve(words, result, charset, char_int_map, used)) {
          return true;
        }
        used[i] = false;
        char_int_map.erase(c);
      }
      return false;
    }
    return false;

  }



  bool isSolvable(std::vector<std::string>& words, std::string result) {
    auto size = words.size();
    // 字母和数字的映射
    std::unordered_map<char, int> char_int_map;
    // 所有的字母集合
    std::unordered_set<char> charset;
    for (auto c : result) {
      charset.insert(c);
    }

    size_t max_word_len = 0;
    for (auto& word : words) {
      max_word_len = std::max(max_word_len, word.size());
      for (auto c : word) {
        charset.insert(c);
      }
    }

    // 哪些数字被使用了
    std::vector<bool> used(10, false);

    if (max_word_len > result.size()) return false;
    if (max_word_len == result.size()) {
      return solve(words, result, charset, char_int_map, used);
    }
    for (int i = 1; i <= words.size(); ++i) {
      char_int_map[result[0]] = i;
      used[i] = true;
      if (solve(words, result, charset, char_int_map, used)) return true;
      used[i] = false;
    }
    return false;

  }
};


// map/unordered_map 都必须加这个
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& v) {
  out << "{" << v.first << "," << v.second << "}";
  return out;
}

int main(int argc, char* argv[]) {
  std::unordered_map<char, int> test = {
      {'a', 1},
      {'b', 2}
  };
  dbg(test);
  Solution s;
  std::vector<std::string> words = {"LEET", "CODE"};
  std::string result = "POINT";
  std::cout << s.isSolvable(words, result) << std::endl;

  return 0;
}
