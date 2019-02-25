#include <iostream> 
#include <vector>
#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
  if (s1.size() + s2.size() != s3.size()) return false;
  // f[i][j] = s1[i - 1] == s3[i + j - 1] && f[i - 1][j]
  // f[i][j] = s2[j - 1] == s3[i + j - 1] && f[i][j - 1]
  vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
  for (int j = 0; j <= s2.size(); ++j) {
    dp[0][j] = (0 == strncmp(s2.c_str(), s3.c_str(), j));
  }
  for (int i = 0; i <= s1.size(); ++i) {
    dp[i][0] = (0 == strncmp(s1.c_str(), s3.c_str(), i));
  }
  for (int i = 1; i <= s1.size(); ++i) {
    for (int j = 1; j <= s2.size() ; ++j) {
      dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])||
                 (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
    }
  }
  return dp[s1.size()][s2.size()];

}

int main(int argc, const char *argv[])
{
    string s1 = "aa";
    string s2 = "ab";
    string s3 = "aaba";
    cout << "s1 => " << s1 << endl;
    cout << "s2 => " << s2 << endl;
    cout << "s3 => " << s3 << endl;
    cout << isInterleave(s1, s2, s3) << endl;

    return 0;
}


