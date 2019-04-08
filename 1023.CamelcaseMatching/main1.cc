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
    int i = 0;
    int j = 0;
    while (i < source.size() && j < pattern.size()) {
      if (source[i] == pattern[j]) {
        i += 1;
        j += 1;
        continue;
      }
      if (isupper(source[i])) return false;
      i += 1;
    }
    if (j < pattern.size()) return false;
    for (;i < source.size(); ++i) {
      if (isupper(source[i])) return false;
    }
    return true;
  }
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vecotr<bool> result;
    for (const auto& query : queries) {
      result.push_back(match(query, pattern));
    }
    return result;
  }
};

int main(int argc, const char *argv[]) {
  Solution s;
  cout << s.match("FooBar", "FB") << endl;
  return 0;
}


