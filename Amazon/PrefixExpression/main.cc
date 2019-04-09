//
// Created by alexkkk on 2019-02-26.
//

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


/*
 * (* 1 2 3 (+ 1 2 3)) = 36
 * 表达式求值
 */

string GetNextExp(std::string& s, std::string::iterator& start) {
  if ('(' == *start) {
    // exp
    int count = 1;
    auto it = start + 1;
    for (; it != s.end() && count > 0; ++it) {
      if ('(' == *it) count += 1;
      if (')' == *it) count -= 1;
    }
    std::string result = string(start, it);
    start = it;
    return result;
  }
  auto end = std::find(start, s.end(), ' ');
  std::string result = string(start, end);
  start = end;
  return result;
}


int eval(std::string s) {
  cout << "expresson: " << s << endl;
  if ('(' == s[0]) {
    return eval(s.substr(1, s.size() - 2));
  }
  if ('0' <= s[0] && s[0] <= '9') {
    return stoi(s);
  }
  auto start = s.begin();
  auto op = GetNextExp(s, start);
  cout << "op: " << op << endl;
  if ("+" == op) {
    int result = 0;
    while (true) {
      auto strx = GetNextExp(s, ++start);
      cout << "1---> strx: " << strx << endl;
      int x = eval(strx);
      cout << "1---> x: " << x << endl;
      result += x;
      cout << "1---> result: " << result << endl;
      if (start == s.end()) {
        return result;
      }
    }
  } else if ("*" == op) {
    int result = 1;
    while (true) {
      auto strx = GetNextExp(s, ++start);
      cout << "2---> strx: " << strx << endl;
      int x = eval(strx);
      cout << "2---> x: " << x << endl;
      result *= x;
      cout << "2---> result: " << result << endl;
      if (start == s.end()) {
        return result;
      }
    }
  }
  return 0;
}


int main(int argc, char* argv[]) {
  cout << eval("(* 1 2 3 (+ 1 2 3))") << endl;
  return 0;
}

