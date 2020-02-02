//
// Created by alexkkk on 2020/1/29.
//

#include <string>
#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    int N = s1.size();
    if (N != s2.size()) return false;
    bool f[N + 1][N][N];
    fill_n(&f[0][0][0], (N + 1) * N * N, false);

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        f[1][i][j] = (s1[i] == s2[j]);
      }
    }

    for (int len = 2; len <= N; ++len) {
      for (int i = len - 1; i < N; ++i) {
        for (int j = len - 1; j < N; ++j) {
          for (int k = 1; k < len; ++k) {
            if (f[k][i - len + k][j - len + k] && f[len - k][i][j]) {
              f[len][i][j] = true;
              break;
            }
            if (f[k][i - len + k][j] && f[len - k][i][j - k]) {
              f[len][i][j] = true;
              break;
            }
            cout << "len:" << len << " i:" << i << " j:" << j << endl;
            dbg(f[len][i][j]);
          }
        }
      }
    }

    cout <<  f[N][N - 1][N - 1] << endl;
    return f[N][N - 1][N - 1];
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  string s1 = "aa";
  string s2 = "ab";
  dbg(s.isScramble(s1, s2));
  return 0;
}