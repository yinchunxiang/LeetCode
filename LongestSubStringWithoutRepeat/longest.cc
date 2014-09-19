#include <string>   
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int alpha[256] = {0};
    int max_len = 0;
    int cur_len = 0;
    int start = 0;
    for(int i = 0; i < s.size(); ++i) {
        if (0 >= alpha[s[i]]) {
            ++ cur_len;
            if (cur_len > max_len) {
                max_len = cur_len;
            }
            ++ alpha[s[i]];
        }
        else {
            for (int j = start; j < i; ++j) {

                if (s[j] == s[i]) {
                    start = j + 1;
                    break;
                }
                else {
                    -- alpha[s[i]];
                    -- cur_len;
                }

            }
        }
    }
    return max_len;
}

int main(int argc, const char *argv[])
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
