//
// Created by alexkkk on 2020/3/9.
//

#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  int strongPasswordChecker(string s) {
    int need = 3;

    auto N = s.size();
    int need_insert = max(0, 6 - N);
    int need_delete = max(0, N - 20);
    for (int l = 0, i = 0; i < N; ++i) {
      if (isupper(s[i])) need -= 1;
      if (islower(s[i])) need -= 1;
      if (isdigit(s[i])) need -= 1;
    }

    if (N < 6) {
      int actual_insert = 0;
      for (int l = 0, i = 0; i < N; ++i) {
        // 检查重复
        if (i - l == 2 && s[l] == s[l + 1] && s[l + 1] == s[i]) {
          actual_insert += 1;
          l = i;
        }
      }
      return std::max({need, need_insert, actual_insert});
    } else if (N <= 20){
      int replace = 0;
      for (int l = 0, i = 0; i < N; ++i) {
        // 检查重复
        if (i - l == 2 && s[l] == s[l + 1] && s[l + 1] == s[i]) {
          replace += 1;
          l = i + 1;
        }
      }
      return std::max(replace, need);
    } else {

    }


  }
};


int main(int argc, char* argv[]) {

  return 0;
}

