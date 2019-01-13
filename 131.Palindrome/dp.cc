#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  void Init(const std::string& s) {
    auto size = s.size();
    palindromic_ = std::move(vector<vector<bool>>(size, vector<bool>(size, false)));
    for (auto i = 0; i < size; ++i) {
      for (auto j = i; j < size; ++j) {
        if (j - i < 2) {
          palindromic_[i][j] = true;
          continue;
        }
        palindromic_[i][j] = (s[i] == s[j] && palindromic_[i + 1][j - 1]);
      }
    }
  }
  bool IsPalindromic(const std::string& s, int start, int end) {
    assert(start <= end);
    while (start < end) {
      if (s[start++] != s[end--]) return false;
    };
    return true;
  }

  std::vector<std::vector<string>> partition(string s) {
    Init(s);
    // result[i] 表示前 N 个字符的所有的切出来是 palindrome 的方式
    std::vector<std::vector<std::vector<std::string>>> result = {{{}}};
    for (int i = 1; i <= s.size(); ++i) {
      result.emplace_back();
      for (auto j = 0; j < i; ++j) {
        if (!IsPalindromic(s, j, i - 1)) continue;
        for (auto r : result[j]) {
          std::string partition = s.substr(j, i - j);
          r.push_back(partition);
          result[i].push_back(r);
        }
      }
    }
    return result[s.size()];
  }
 private:
  vector<vector<bool>> palindromic_;
};

void printv(const std::vector<string>& v) {
  string s;
  for (const auto& str : v) {
    s += str + ",";
  }
  std::cout << s << endl;
}

int main(int argc, const char *argv[]) {
  Solution s;
  {
    auto result = s.partition("aab");
    for (const auto &v : result) {
      printv(v);
    }
  }
  return 0;
}
