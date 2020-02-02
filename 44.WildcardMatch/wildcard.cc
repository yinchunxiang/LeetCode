#include <iostream>

using namespace std;

// 贪心算法，时间复杂度O(M + N);
bool isMatch(const char *s, const char *p) {
    if ('*' == *p) {
        while('*' == *p) ++p;
//        p 到结尾都是 *
        if ('\0' == *p) return true;
//        * 匹配 s 没有到结束
        while ('\0' != *s && !isMatch(s, p)) {
            ++s;
        }
        return '\0' != *s;
    } else if (*s == *p || '?' == *p) {
        ++p;
        ++s;
        return isMatch(s, p);
    } else if ('\0' == *p || '\0' == *s) {
        return *p == *s;
    } else {
        return false;
    }
}

bool isMatch2(const char *s, const char *p) {
    bool star = false;
    const char* str = NULL;
    const char* ptr = NULL;
    while ('\0' != *s) {
        if ('*' == *p) {
            star = true;
            while('*' == *p) ++p;
            if ('\0' == *p) return true;
            str = s;
            ptr = p;
            continue;
        }
        if (*s == *p || '?' == *p) {
            ++s;
            ++p;
            continue;
        }
        if (star) {
            ++str;
            s = str;
            p = ptr;
            continue;
        }
        return false;
    }

    while ('*' == *p) ++p;

    return '\0' == *p;
}

int main(int argc, const char *argv[])
{
    cout <<   ( isMatch("aa","a") == isMatch2("aa","a"))<< endl;// → false
    cout <<   ( isMatch("aa","aa") == isMatch2("aa","aa"))<< endl;// → true
    cout <<   ( isMatch("aaa","aa") == isMatch2("aaa","aa"))<< endl;// → false
    cout <<   ( isMatch("aa", "*") == isMatch2("aa", "*"))<< endl;// → true
    cout <<   ( isMatch("aa", "a*") == isMatch2("aa", "a*"))<< endl;// → true
    cout <<   ( isMatch("ab", "?*") == isMatch2("ab", "?*"))<< endl;// → true
    cout <<   ( isMatch("aab", "c*a*b") == isMatch2("aab", "c*a*b"))<< endl;// → false
    cout <<   ( isMatch("ab", "*?*?*") == isMatch2("ab", "*?*?"))<< endl;// → false
    cout <<   isMatch2("hi", "*?")<< endl;// → false
    return 0;
}
