#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    int n = s.size();
    bool f[n][n];
    fill_n(&f[0][0], n * n, false);
    int max_size = 1;
    int start = 0;
    for (int i = n - 1; i >= 0; --i) {
        f[i][i] = true;
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = (s[i] == s[j] && (j == i + 1 || f[i+1][j-1]));
            if (f[i][j] && j - i + 1 > max_size) {
                max_size = j - i + 1;
                start = i;
            }
            printf("f[%d][%d]:%d max_size: %d, start: %d\n" , i, j, f[i][j], max_size, start);
        }
    }
    cout << "start: " << start << " max_size: " << max_size << endl;
    return s.substr(start, max_size);;
}


int main(int argc, const char *argv[])
{
    /*
    {
        string s = "a" ;
        cout << longestPalindrome(s) << endl;
    }
    {
        string s = "abaac" ;
        cout << longestPalindrome(s) << endl;
    }
    {
        string s = "abccdccb" ;
        cout << longestPalindrome(s) << endl;
    }
    */
    {
        string s = "abb" ;
        cout << longestPalindrome(s) << endl;
    }
    return 0;
}
