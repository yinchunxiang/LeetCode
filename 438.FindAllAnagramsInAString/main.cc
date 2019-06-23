//
// Created by alexkkk on 2019-05-11.
//
#include <vector>
#include <string>
#include "ThirdParty/PrettyPrinter/pprint.hpp"

using namespace std;


class Solution {
public:
  // yinchunxiang@2019-05-11: 可以直接用 = 比较 vector， 这个函数就省略了
  bool same(const vector<int>& l, const vector<int>& r) {
    int ls = l.size();
    int rs = r.size();
    if (ls != rs) return false;
    for (int i = 0; i < ls; ++i) {
      if (l[i] != r[i]) return false;
    }
    return true;
  }
  // yinchunxiang@2019-05-11: 写完代码自己举几个corner case 和 正常 case 测试下
  /**
   * M 代表pattern长度
   * N 代表source 长度
   * Time Complexity: O(N + M * (N - M + 1)) => O(MN)
   * Space Complexity: O(M)
   */

  vector<int> findAnagrams(string s, string p) {
    std::vector<int> result;
    if (s.size() < p.size()) return result;
    vector<int> pattern(26, 0);
    vector<int> window(26, 0);
    for (int i = 0; i < p.size(); ++i) {
      pattern[p[i] - 'a'] += 1;
      window[s[i] - 'a'] += 1;
    }
    // 这一句千万不能忘记
    if (pattern == window) result.push_back(0);

    for (int i = p.size(); i < s.size(); ++i) {
      window[s[i] - 'a'] += 1;
      window[s[i - p.size()] - 'a'] -= 1;
      if (window == pattern) {
        result.push_back(i - p.size() + 1);
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  auto result = s.findAnagrams("ababc", "ab");
  pprint::PrettyPrinter printer;
  printer.print(result);

  return 0;
}