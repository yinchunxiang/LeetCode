//
// Created by alexkkk on 2019-02-13.
//

class Solution {
public:
  bool isScramble(string s1, string s2) {
    const int N = s1.size();
    if (N != s2.size()) return false;
    bool f[N + 1][N][N];
    fill_n(&f[0][0][0], (N + 1) * N * N, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            f[1][i][j] = s1[i] == s2[j];
        }
    }

    for (int len = 1; len <= N; ++len) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 1; k < len; ++k) {
                  if (f[k][i][j] && f[len - k][i + k][j + k]) return true;
                  if (f[k][i][j + len - k] && f[len - k][i + k][j]) return true;
                }
            }
        }
    }
    return f[N][0][0];
  }
};


