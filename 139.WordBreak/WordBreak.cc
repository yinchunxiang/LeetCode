#include <iostream>
#include <tr1/unordered_set>
#include <string>
#include <vector>

using namespace std;

typedef std::tr1::unordered_set<string> StrSet;

bool wordBreak(string s, StrSet &dict) {
    if(dict.empty() || s.empty()) {
        return false;
    }
    vector<bool> f(s.size() + 1, false);
    f[0] = true;

    for(int i = 0; i < s.size(); ++i) {
        for( int j = 0; j <= i; ++j) {
            string sub = s.substr(j, i-j+1);
            cout << "sub => " << sub << endl;
            bool is_in_dict = false;
            if (dict.end() != dict.find(sub)) {
                is_in_dict = true;
            }
            f[i + 1] = f[j] && is_in_dict;
            if (f[i + 1]) {
                break;
            }
        }
    }

    return f[s.size()];

}

/*
bool dfs (const string& s, StrSet& dict, int start, int cur) {
    if (s.size() - 1 == cur) {
        return dict.end() != dict.find(s.substr(start, cur - start + 1));
    }


    if (dfs(s, dict, start, cur + 1)) {
        return true;
    }

    if ( dict.end() == dict.find(s.substr(start, cur - start + 1)) ) {
        return false;
    }
    return dfs(s, dict, cur+1, cur+1);
}
*/


bool dfs(const string &s, StrSet &dict, size_t start, size_t cur) {
    if (cur == s.size()) {
        return dict.find(s.substr(start, cur-start+1)) != dict.end();
    }
    if (dfs(s, dict, start, cur+1)) return true;
    if (dict.find(s.substr(start, cur-start+1)) != dict.end())
        if (dfs(s, dict, cur+1, cur+1)) return true;
    return false;
}

int main() {
    string s = "abcd";
    string a[] = { "a", "abc", "b", "cd"};
    StrSet dict(a, a + 4);
    cout << wordBreak(s, dict) << endl;
    cout << dfs(s, dict, 0, 0)<< endl;

    s = "dogs";
    string b[] = { "dog", "s", "gs"};
    StrSet dictb(b, b + 3);
    cout << wordBreak(s, dictb) << endl;
    cout << dfs(s, dictb, 0, 0)<< endl;

}
