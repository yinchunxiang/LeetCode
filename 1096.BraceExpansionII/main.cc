//
// Created by alexkkk on 2019-06-23.
//

/**
 * Under a grammar given below, strings can represent a set of lowercase words.  Let's use R(expr) to denote the set of words the expression represents.

Grammar can best be understood through simple examples:

Single letters represent a singleton set containing that word.
R("a") = {"a"}
R("w") = {"w"}
When we take a comma delimited list of 2 or more expressions, we take the union of possibilities.
R("{a,b,c}") = {"a","b","c"}
R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
R("{a{b,c}}{{d,e},f{g,h}}") = R("{ab,ac}{dfg,dfh,efg,efh}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
Formally, the 3 rules for our grammar:

For every lowercase letter x, we have R(x) = {x}
For expressions e_1, e_2, ... , e_k with k >= 2, we have R({e_1,e_2,...}) = R(e_1) ∪ R(e_2) ∪ ...
For expressions e_1 and e_2, we have R(e_1 + e_2) = {a + b for (a, b) in R(e_1) × R(e_2)}, where + denotes concatenation, and × denotes the cartesian product.
Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.



Example 1:

Input: "{a,b}{c{d,e}}"
Output: ["acd","ace","bcd","bce"]
Example 2:

Input: "{{a,z},a{b,c},{ab,z}}"
Output: ["a","ab","ac","z"]
Explanation: Each distinct word is written only once in the final answer.


Constraints:

1 <= expression.length <= 50
expression[i] consists of '{', '}', ','or lowercase English letters.
The given expression represents a set of words based on the grammar given in the description.
*/

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <set>
#include "../util/base.h"
//#include "../util/easylogging++.h"

//INITIALIZE_EASYLOGGINGPP

using namespace std;


class Solution {
public:
  int GetSubExpSize(const string& exp) {
    int count = 0;
    for (int i = 0; i < exp.size(); ++i) {
      if ('}' == exp[i]) {
        count -= 1;
        if (0 == count) return i + 1;
      }
      if ('{' == exp[i]) count += 1;
      if (0 == count && ',' == exp[i]) {
        return i;
      }
    }
    return exp.size();
  }

  vector<string> Add(const vector<string>& l, const vector<string>& r) {
    vector<string> result;
    result.insert(result.end(), l.begin(), l.end());
    result.insert(result.end(), r.begin(), r.end());
    return result;
  }

  vector<string> Multiply(const vector<string>& l, const vector<string>& r) {
    if (r.empty()) return l;
    vector<string> result;
    for (const auto& a : l) {
      for (const auto& b: r) {
        result.push_back(a + b);
      }
    }
    return result;
  }

  vector<string> expand(string rest) {
    if (rest.empty()) return {};
    cout << "--> expand: " << rest << endl;
    // 第一个字符是 "{"
    if ('{' == rest[0]) {
      auto sub_exp_size = GetSubExpSize(rest);
      cout << "1----> sub_exp_size: " << sub_exp_size << endl;
      auto l = expand(rest.substr(0, sub_exp_size));
      if (sub_exp_size >= rest.size()) return l;
      if (',' == rest[sub_exp_size]) {
        auto r = expand(rest.substr(sub_exp_size + 1));
        return Add(l, r);
      } else {
        auto r = expand(rest.substr(sub_exp_size));
        return Multiply(l, r);
      }
    }
    // 第一个字符是字母
    int sub_exp_size = 0;
    for (auto c : rest) {
      if (c <'a' || c > 'z') break;
      sub_exp_size += 1;
    }
    cout << "2----> sub_exp_size: " << sub_exp_size << endl;
    vector<string> l;
    l.push_back(rest.substr(0, sub_exp_size));
    if (sub_exp_size >= rest.size()) return l;
    if (',' == rest[sub_exp_size]) {
      auto r = expand(rest.substr(sub_exp_size + 1));
      return Add(l, r);
    }
    if ('{' == rest[sub_exp_size]) {

      auto r = expand(rest.substr(sub_exp_size));
      return Multiply(l, r);
    }
    cout << "SHOULD NOT BE HERE" << endl;
    return l;
  }

  vector<string> braceExpansionII(string expression) {
//    return expand(expression);
    auto v = ExpandByAdd(std::move(expression));
    set<string> s(v.begin(), v.end());
    return vector<string>(s.begin(), s.end());
  }

  int GetBraceExpLen(string& exp) {
    int count = 1;
    for (int i = 1; i < exp.size(); ++i) {
      if ('}' == exp[i]) count -= 1;
      if ('{' == exp[i]) count += 1;
      if (0 == count) return i + 1;
    }
    return exp.size();
  }

  int GetCharExpLen(string& exp) {
    for (int i = 1; i < exp.size(); ++i) {
      if (exp[i] < 'a' || exp[i] > 'z') return i;
    }
    return exp.size();
  }


  // 找出可以相乘的子串
  vector<string> ExpandByMul(string exp) {
    vector<string> result;
    if (exp.empty()) return result;
    cout << "--> expand by mul: " << exp << endl;
    if ('{' == exp[0]) {
      auto brace_exp_len = GetBraceExpLen(exp);
      auto l = ExpandByAdd(exp.substr(1, brace_exp_len - 2));
      auto r = ExpandByMul(exp.substr(brace_exp_len));
      return Multiply(l, r);
    }
    auto char_exp_len = GetCharExpLen(exp);
    vector<string> l {exp.substr(0, char_exp_len)};
    auto r = ExpandByMul(exp.substr(char_exp_len));
    return Multiply(l, r);
  }


  // 找出可以相加的子串
  vector<string> ExpandByAdd(string exp) {
    vector<string> result;
    if (exp.empty()) return result;
    cout << "--> expand by add: " << exp << endl;
    int count = 0;
    for (int i = 0; i < exp.size(); ++i) {
      auto c = exp[i];
      if ('{' == c) count += 1;
      if ('}' == c) count -= 1;
      if (',' == c && 0 == count) {
        auto l = ExpandByMul(std::move(exp.substr(0, i)));
        auto r = ExpandByAdd(std::move(exp.substr(i + 1)));
        return Add(l, r);
      }
    }
    return ExpandByMul(exp);

  }


};

int main(int argc, char* argv[]) {
  Solution s;
  {
    auto result = s.braceExpansionII("{a,b}{c{d,e}}");
    printv(result);
  }
  {
    auto result = s.braceExpansionII("{{a,z},a{b,c},{ab,z}}");
    printv(result);
  }
  return 0;
}