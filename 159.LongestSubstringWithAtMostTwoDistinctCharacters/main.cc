//
// Created by alexkkk on 2020/2/4.
//

#include <string>
#include <unordered_map>
#include "../util/dbg.h"

using namespace std;

//using std::string;
//using std::unordered_map;

class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int N = s.size();
    if (N <= 2) return s.size();
    unordered_map<char, int> chars;
    int start = 0; // 代表下一个开始的地方
    int end = start;
    int result = 0;
    while (end < N) {
      dbg(end);
      dbg(start);
      // 插入当前元素
      chars[s[end++]] += 1;
      while (chars.size() > 2) {
        chars[s[start]] -= 1;
        if (chars[s[start]] == 0) {
          chars.erase(s[start]);
        }
        start += 1;
      }
      result = max(result, end - start);
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  string input = "ccaabbb";
  dbg(s.lengthOfLongestSubstringTwoDistinct(input));
  return 0;
}

