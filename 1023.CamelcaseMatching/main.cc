//
// Created by yinchunxiang on 2019-04-08.
//
/*
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.



Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation:
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation:
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation:
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".


Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool match(const std::string& source, const std::string& pattern) {
    if (source.empty() && pattern.empty()) return true;
    if (source.empty() || pattern.empty()) return false;
    if (pattern.size() > source.size()) return false;
    if (pattern.size() == source.size()) return pattern == source;

    int i = 0;
    int j = 0;
    for (; i < source.size() && j < pattern.size();) {
      // 判断pattern的所有小写字母是不是在source里面能找到
      bool matched = true;
      // pattern到最后或者遇到大写
      while (islower(pattern[j]) && j < pattern.size()) {
        if (isupper(source[i]) || i >= source.size()) {
          matched = false;
          break;
        }
        if (source[i] == pattern[j]) {
          j += 1;
        }
        i += 1;
      }
      if (!matched) return false;
      // source 到最后或者遇到大写
      while (islower(source[i]) && i < source.size()) {
        i += 1;
      }

      // pattern/source都结束
      if (i >= source.size() && j >= pattern.size()) {
        return true;
      }
      // pattern/source都没结束，判断他们是不是相同的大写字母
      if (i < source.size() && j < pattern.size()) {
        if (source[i] != pattern[j]) return false;
        i += 1;
        j += 1;
        continue;
      }
      // source 结束
      if (i >= source.size()) {
        return false;
      }
      // pattern 结束, 检查source剩下的部分是否有大写字母
      if (j >= pattern.size()) {
        while (i < source.size()) {
          if (isupper(source[i])) return false;
        }
        return true;
      }
    }
    while (i++ < source.size()) {
      if (isupper(source[i])) return false;
    }
    if (j < pattern.size()) {
      return false;
    }
    return true;
  }
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    // TODO
    return {true};
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  cout << s.match("FooBar", "FB") << endl;
  return 0;
}


