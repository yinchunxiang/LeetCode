#include <iostream>

using namespace std;

bool isMatch(const char *s, const char *p) {
    //check whether string is empty
    if (*p == '\0') return *s == '\0';

    //next character is not '*'
    if ('*' != *(p + 1)) {
        if (*p == *s || (*p == '.' && *s != '\0')) {
            return isMatch(s + 1, p + 1) ;
        }
        else {
            return false;
        }
    }

    //next character is '*'
    while (*p == *s || (*p == '.' && *s != '\0')) {
        if (isMatch(s + 1, p + 2)) {
            return true;
        }
        s ++;
    }

    return isMatch(s, p + 2);
}

int main(int argc, const char *argv[])
{
    cout << isMatch("aa","a") << endl;
    cout << isMatch("aa","aa") << endl;
    cout << isMatch("aaa","aa") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("aa", ".*") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    return 0;
}
