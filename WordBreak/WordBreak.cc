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
    vector<bool> f(s.size(), false);
    if(dict.end() != dict.find(s.substr(0,1))) {
        f[0] = true;
    }

    for(int i = 1; i < s.size(); ++i) {
        for( int j = 0; j < i; ++j) {
            string sub = s.substr(j+1, i-j);
            cout << "sub => " << sub << endl;
            bool is_in_dict = false;
            if (dict.end() != dict.find(sub)) {
                is_in_dict = true;
            }
            f[i] = f[j] && is_in_dict;
            if (f[i]) {
                break;
            }
        }
    }

    return f[s.size() -1];

}


int main() {
    string s = "abcd";
    string a[] = { "a", "abc", "b", "cd"};
    StrSet dict(a, a + 4);
    cout << wordBreak(s, dict) << endl;

    s = "dogs";
    string b[] = { "dog", "s", "gs"};
    StrSet dictb(b, b + 3);
    cout << wordBreak(s, dictb) << endl;

}
