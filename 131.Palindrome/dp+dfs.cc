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

  // [start, end)
  void dfs(vector<vector<string>>& global, vector<string>& local, const string& s, int start) {
    if (start >= s.size()) {
      global.push_back(local);
      return;
    }
    for (int end = start + 1; end <= s.size(); ++end) {
      if (!IsPalindromic(s, start, end - 1)) continue;
      local.push_back(s.substr(start, end - start));
      dfs(global, local, s, end);
      local.pop_back();
    }
  }

  std::vector<std::vector<string>> partition(string s) {
    Init(s);
    // result[i] 表示前 N 个字符的所有的切出来是 palindrome 的方式
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> path;
    dfs(result, path, s, 0);
    return result;
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

// 这种方法最快
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
