//
// Created by alexkkk on 2019-05-12.
//

/**
 *

Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)



Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""


Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
 *
 */

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

#include "../ThirdParty/PrettyPrinter/pprint.hpp"

using namespace std;

pprint::PrettyPrinter printer;

void PrintSet(const unordered_set<std::string>& s) {
  std::cout << "{" << std::endl;
  for (const auto& str : s) {
    cout << str << "," << endl;
  }
  std::cout << "}" << std::endl;
}


class Solution {
public:
  bool is_there_dup(const std::string& s, int len, string& result) {
    unordered_set<string> dups;
    for (int i = 0; i <= s.size() - len; ++i) {
      auto sub = s.substr(i, len);
      cout << "---> sub: " << sub << endl;
//      printer.print("----> dups:", dups);
      cout << "---> dups:" << endl;
      PrintSet(dups);
      auto it = dups.find(sub);
      if (it != dups.end()) {
        result = std::move(sub);
        cout << "=> current dup:" << result << endl;
        return true;
      }
      dups.insert(sub);
    }
    return false;
  }
  string longestDupSubstring(string S) {
    int N = S.size();
    if (N <= 0) return "";
    unordered_set<char> char_set(S.begin(), S.end());
    if (N == char_set.size()) return "";
    int low = 1;
    int high = N;
    int current_max_len = 0;
    string result;
    while (low < high) {
      int mid = (low + high) / 2;
      string current_result;
      if (is_there_dup(S, mid, current_result)) {
        current_max_len = mid;
        result = std::move(current_result);
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  auto result = s.longestDupSubstring("banana");
  cout << "--> result: " << result << endl;
  return 0;
}