//
// Created by alexkkk on 2019-07-13.
//

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

vector<vector<char>> keyboard;

using CharPosMap = unordered_map<char, std::pair<int, int>>;
CharPosMap char_pos_map;


std::string Get(const std::string& input) {
  std::pair<int, int> cur(0, 0);
  vector<pair<int, int>> pos_list;
  for (auto c : input) {
    pos_list.push_back(char_pos_map[c]);
  }
  std::string result;
  for (const auto& pos : pos_list) {
    if (cur == pos) {
      result.push_back('E');
      continue;
    }
    while (cur != pos) {
      // 判断 x, 比较的是在哪一行
//      if (cur.first > pos.first) {
        while (cur.first > pos.first) {
          result.push_back('U');
          cur.first -= 1;
        }
//        if (cur == pos) {
//          result.push_back('E');
//        }
//      }
//      if (cur.first < pos.first) {
        while (cur.first < pos.first && cur.second < keyboard[cur.first + 1].size()) {
          result.push_back('D');
          cur.first += 1;
        }
//        if (cur == pos) {
//          result.push_back('E');
//        }
//      }

      // 判断y， 判断的是列
//      if (cur.second < pos.second) {
        while (cur.second < pos.second && cur.second < keyboard[cur.first].size()) {
          result.push_back('R');
          cur.second += 1;
        }
//        if (cur == pos) {
//          result.push_back('E');
//        }
//      }

//      if (cur.second > pos.second) {
        while (cur.second > pos.second) {
          result.push_back('L');
          cur.second -= 1;
        }
//        if (cur == pos) {
//          result.push_back('E');
//        }
//      }
    }
    result.push_back('E');
  }
  return result;
}

int main(int argc, char* argv[]) {
  keyboard.push_back({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'});
  keyboard.push_back({'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'});
  keyboard.push_back({'T', 'U', 'V', 'W', 'X', 'Y', 'Z'});

  for (int i = 0; i < keyboard.size(); ++i) {
    const auto& row = keyboard[i];
    for (int j = 0; j < row.size(); ++j) {
      char_pos_map.emplace(keyboard[i][j], std::make_pair(i, j));
    }
  }

  std::string input;
  input = "BAT";
  cout << input << " => " << Get(input) << endl;
  input = "AAZR";
  cout << input << " => " << Get(input) << endl;
  input = "AZBC";
  cout << input << " => " << Get(input) << endl;
  input = "AJS";
  cout << input << " => " << Get(input) << endl;


  return 0;
}

