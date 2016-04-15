#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

typedef std::tr1::unordered_set<string> StrSet;


/*
bool dfs(string s, int cur,  StrSet& dict, string sub, vector<string>& result, vector<bool>& possible) {
    cout << " s => [" << s << "]" << endl;
    if (cur == s.size()) {
        if (!sub.empty()) {
            result.push_back(sub);
        }
        return true;
    }

    bool ret = false;
    for(int i = cur; i < s.size(); ++i) {
        string temp = s.substr(cur, i - cur + 1);
        if (dict.end() != dict.find(temp) && possible[i + 1]) {
            string cursub = sub;
            if (!cursub.empty()) {
                cursub += " ";
            }
            cursub += temp;
            cout << "[" << i << "] s => " << s << " sub => " << sub << endl;
            cout << "[" << i << "] s => " << s << " cursub > " << cursub << endl;
            if(!dfs(s, i + 1, dict, cursub, result, possible)) {
                possible[i + 1] = false;
            }
            else {
                ret = true;
            }
        }
    }

    return ret;
}

vector<string> WordBreakII(string s, StrSet& dict) {
    vector<string> ret;
    string sub = "";
    vector<bool> possible(s.size() + 1, true);
    dfs(s, 0, dict, sub, ret, possible);
    return ret;
}
*/

    void dfs(const string& s, const vector<vector<bool> >& prev, int curr, vector<string>& path, vector<string>& result) {
        if (curr >= s.size()) {
            string temp;
            for (int i = 0; i < path.size(); ++i) {
                if (i > 0) {
                    temp += " ";
                }
                temp += path[i];
            }
            result.push_back(temp);
            return;
        }
        
        for (int i = curr; i < s.size(); ++i) {
            if (prev[curr][i]) {
                path.push_back(s.substr(curr, i - curr + 1));
                dfs(s, prev, i + 1, path, result);
                path.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<string> result;
        if (0 == n) return result;
        vector<vector<bool> > prev(n + 1, vector<bool>(n, false));
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    f[i] = true;
                    prev[j][i] = true;
                }
            }
        }
        
        vector<string> path;
        dfs(s, prev, 0, path, result);
        return result;
    }

void print_str_vec(vector<string> vs) {
    for( int i = 0; i < vs.size(); ++i) {
        cout << "[" << vs[i] << "]" <<  endl;
    }
}

void print_set(StrSet& str_set) {
    StrSet::iterator it = str_set.begin();
    for(; it != str_set.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

}

int main() {
    vector<string> ret;
    string s = "abcd";
    string a[] = { "a", "abc", "b", "cd"};
    StrSet dict(a, a + 4); 
    ret = WordBreakII(s, dict);
    cout << "input " << s << endl;
    print_set(dict);
    print_str_vec(ret);

    s = "dogs";
    string b[] = { "dog", "s", "gs"};
    StrSet dictb(b, b + 3); 
    ret = WordBreakII(s, dictb);
    cout << "input " << s << endl;
    print_set(dictb);
    print_str_vec(ret);

    s = "catsanddog";
    string c[] = {"cat","cats","and","sand","dog"};
    StrSet dictc(c, c + 5); 
    ret = WordBreakII(s, dictc);
    cout << "input " << s << endl;
    print_set(dictc);
    print_str_vec(ret);

    s = "aaaaaaa";
    string d[] = {"aaaa","aaa"};
    StrSet dictd(d, d + 2); 
    ret = WordBreakII(s, dictd);
    cout << "input " << s << endl;
    print_set(dictd);
    print_str_vec(ret);

    s = "a";
    string e[] = {"a"};
    StrSet dicte(e, e + 1); 
    ret = WordBreakII(s, dicte);
    cout << "input " << s << endl;
    print_set(dicte);
    print_str_vec(ret);
}
