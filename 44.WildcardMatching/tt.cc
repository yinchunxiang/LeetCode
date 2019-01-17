#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool match(const string& s, int start1, const string& p, int start2) {
        // both empty
        if (start1 == s.size() && start2 == p.size()) {
            return true;
        }

        // pattern empty
        if (start2 == p.size()) return false;

        if (start1 == s.size()) {
            for (auto j = start2; j < p.size(); ++j) {
                if ('*' != p[j]) return false;
            }
            return true;
        }

        while (start2 < p.size()) {
            if ('*' == p[start2]) {
                for (int i = start1; i < s.size(); ++i) {
                    if (match(s, i, p, start2 + 1)) {
                        return true;
                    }
                }
            } else if ('?' == p[start2]) {
                return match(s, start1 + 1, p, start2 + 1);
            } else {
                return s[start2] == p[start2] && match(s, start1 + 1, p, start2 + 1);
            }
        }

    }
    bool isMatch(string s, string p) {
        if (s.empty()) {
            return p.empty() || p == "*";
        }
        if (p.empty()) return false;

        auto m = s.size();
        auto n = p.size();
        int pi = -1;
        int pj = -1;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if ('*' == p[j]) {
                for (int k = i + 1; k < n; ++k) {
                    if (match(s, k, p, j+ 1)) {
                        return true;
                    }
                }
                return false;
            }
        }



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
