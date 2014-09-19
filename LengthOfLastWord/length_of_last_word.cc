#include <iostream>

using namespace std;


int lengthOfLastWord(const char *s) {
    if (NULL == s) return 0;
    int N = 0;
    while ('\0' != s[N]) {
        N ++;
    }

    // find first alpha
    while (N > 0 && s[N - 1] == ' ') {
        N --;
    }

    if (0 == N) {
        return 0;
    }

    int start = N - 1;
    while (N > 0 && s[N -1] != ' ') {
        N --;
    }

    return start - N + 1;
}

int len2(const char* s) {
    int prev = 0; //0:space 1:alpha
    int len = 0;
    int i = 0;
    while ('\0' != s[i]) {
        if (s[i] != ' ') {
            len ++;
        }
        else {
            if (s[i + 1] && s[i + 1] != ' ') {
                len = 0;
            }
        }
        ++i;
    }
    return len;
}

int main(int argc, const char *argv[])
{
    char* s = "hello world";
    cout << lengthOfLastWord(s) << endl;
    cout << len2(s) << endl;
    return 0;
}
