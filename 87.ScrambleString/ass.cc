#include <string>
#include <iostream>

using namespace std;

bool scramble(const string &s1, int b1, int e1, const string &s2, int b2, int e2) {
    cout << s1.substr(b1, e1 - b1 + 1) << "  " << s2.substr(b2, e2 - b2 + 1) << endl;
    int len1 = e1 - b1 + 1;
    int len2 = e2 - b2 + 1;
    if (len1 != len2) return false;
    if (len1 == 1) return s1[b1] == s2[b2];
    bool issame = true;
    for (int i = 0; i < len1; ++i) {
        if (s1[b1 + i] != s2[b2 + i]) {
            issame = false;
            break;
        }
    }
    if (issame) return true;
    int mid1 = (b1 + e1 + 1)/2;
    int mid2 = (b2 + e2 + 1)/2;
    bool r1 = scramble(s1, b1, mid1 - 1, s2, b2, mid2 - 1) ;
    bool r2 = scramble(s1, mid1, e1, s2, mid2, e2);
    bool r3 = scramble(s1, b1, mid1 - 1, s2, mid2, e2);
    bool r4 = scramble(s1, mid1, e1, s2, b2, mid2 - 1);
    bool result = (r1 && r2) || (r3 && r4);
    if (result) {
        cout << s1.substr(b1, e1 - b1 + 1) << " = " << s2.substr(b2, e2 - b2 + 1) << endl;
    }
    else {
        cout << s1.substr(b1, e1 - b1 + 1) << " != " << s2.substr(b2, e2 - b2 + 1) << endl;
    }
    return result;
}

bool isScramble(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2) return false;
    if (n1 == 0) return true;
    return scramble(s1, 0, n1 - 1, s2, 0, n2 - 1);
}

int main(int argc, const char *argv[])
{
    {
        string s1 = "abb";
        string s2 = "bab";
        cout << isScramble(s1, s2) << endl;
    }    
    return 0;
}
