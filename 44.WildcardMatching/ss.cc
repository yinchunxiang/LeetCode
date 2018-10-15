#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty()) {
            return p.empty() || p == "*";
        }
        if (p.empty()) return false;

        auto m = s.size();
        auto n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < n + 1; ++i) {
            dp[0][i] = ('*' == p[i - 1]) && dp[0][i - 1];
        }

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if ('*' == p[j - 1]) {
                    for (int k = 0; k <= i; ++k) {
                        if (dp[k][j - 1]) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                } else if ('?' == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] && dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char *argv[]) {
    Solution sol;
    //{
    //    string s = "aa";
    //    string p = "a";
    //    cout << s << " " << p << " => "<< sol.isMatch(s, p) << endl;
    //}
    //{
    //    string s = "aa";
    //    string p = "aa";
    //    cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    //}
    //{
    //    string s = "aaa";
    //    string p = "aa";
    //    cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    //}
    {
        string s = "aa";
        string p = "*";
        cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    }
    //{
    //    string s = "aa";
    //    string p = "a*";
    //    cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    //}
    //{
    //    string s = "ab";
    //    string p = "?*";
    //    cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    //}
    //{
    //    string s = "aab";
    //    string p = "c*a*b";
    //    cout << s << " " << p << " => " << sol.isMatch(s, p) << endl;
    //}
    return 0;
}
