#include <iostream>
#include <string>


using namespace std;

int min2(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    int f[n + 1];
    for (int i = 0; i < n + 1; ++i){
        f[i] = i;
    }

    for (int i = 1; i < m + 1; ++i) {
        int prev = i;
        for (int j = 1; j < n + 1; ++j){
            if (word1[i - 1] == word2[j - 1]) {
                //f[j] = f[j - 1];
                f[j - 1] = prev;
                prev = f[j];
            }
            else {
                int mn = min(prev, f[j - 1]);
                f[j] = 1 + min(mn, f[j]);
                f[j - 1] = prev;
                prev = f[j];
            }
        }
    }

    return f[n];

}

int minDistance(string word1, string word2) {  
    int m = word1.size();
    int n = word2.size();
    int f[m+1][n+1];

    for (int i = 0; i < n + 1; ++i){
        f[0][i] = i;
    }

    for (int i = 0; i < m + 1; ++i){
        f[i][0] = i;
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; ++j) {
            if (word1[i] == word2[j]) {
                f[i + 1][j + 1] = f[i][j];
            }
            else {
                f[i + 1][j + 1] = f[i][j] + 1;
                if (f[i][j + 1] + 1 < f[i + 1][j + 1]) {
                    f[i + 1][j + 1] = f[i][j + 1] + 1;
                }
                if (f[i + 1][j] + 1< f[i + 1][j + 1]) {
                    f[i + 1][j + 1] = f[i + 1][j] + 1;
                }
            }
        }
    }

    return f[m][n];
}


int main(int argc, const char *argv[])
{
    string word1 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdef";
    string word2 = "bcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefg";
    cout << minDistance(word1, word2) << endl;
    cout << min2(word1, word2) << endl;;
    return 0;
}
