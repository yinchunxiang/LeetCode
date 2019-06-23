//
// Created by alexkkk on 2019-06-09.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> result;
    auto target = first + " " + second + " ";
    cout << "--> target: {" << target << "}" << endl;
    int search_start = 0;
    while (true) {
      auto pos = text.find(target, search_start);
      cout << "--> pos: " << pos << endl;
      if (pos == std::string::npos) {
        break;
      }
      int start = pos + target.size();
      if (start >= text.size()) break;
      int end = start;
      while (end < text.size() && ' ' != text[end]) {
        ++end;
      }
      auto c = text.substr(start, end - start);
      cout << "--> c: " << c << endl;
      result.push_back(c);
      if (end >= text.size()) break;
      search_start = start;
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  auto text = "alice is a good girl she is a good student";
  auto first = "a";
  auto second = "good";
  s.findOcurrences(text, first, second);

  return 0;
}


