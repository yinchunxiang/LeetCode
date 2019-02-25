//
// Created by alexkkk on 2019-02-15.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  int numDistinct(string s, string t) {
    int sl = s.size();
    int tl = t.size();
    // 注意这里用long， 用int会越界
    vector<vector<long>> dp(sl + 1, vector<long>(tl + 1, 0));
    for (int i = 0; i <= sl; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= sl; ++i) {
      for(int j = 1; j <= tl; ++j) {
        cout << "i:" << i << " j:" << j << endl;
        if (s[i - 1] == t[j - 1]) {
          // 区分使用和不使用s[i - 1]
          // 不使用 + 使用
          cout << "dp[i-1][j]:" << dp[i - 1][j] << " dp[i - 1][j - 1]:" << dp[i - 1][j - 1] << endl;
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        } else {
          // 只有不使用一种情况
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[sl][tl];
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  {
    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    cout << solution.numDistinct(s, t) << endl;

  }
  return 0;
}
