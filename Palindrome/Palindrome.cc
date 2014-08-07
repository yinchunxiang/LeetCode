#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printvv(vector<vector<string> > & vv) {
    vector<vector<string> > ::iterator it = vv.begin();
    for(; it != vv.end(); ++it) {
        vector<string>::iterator jt = it->begin();
        for (; jt != it->end(); ++jt) {
            cout << *jt << " " ;
        }
        cout << endl;
    }
}




bool is_palindrome(const string&s, int begin, int end) {
    while (begin < end) {
        if (s[begin++] != s[end--]) {
            return false;
        }
    }
    return true;
}
void dfs(const string& s, int start, vector<string> path, vector<vector<string> >& result) {
    if (start == s.size()) {
        result.push_back(path);
        return;
    }

    for( int i = start; i < s.size(); ++i) {
        if (is_palindrome(s, start, i)) {
            path.push_back(s.substr(start, i - start +1));
            dfs(s, i + 1, path, result);
            path.pop_back();
        }
    }
}

vector<vector<string> > partition(string s) {
    vector<string> path;
    vector< vector<string> > result;
    dfs(s, 0, path, result);
    return result;
}


void dp(const string& s, int start, vector<string> path, vector<vector<string> >& result, vector<vector<bool> >& pa){
    int n = s.size();
    if (n == start) {
        result.push_back(path);
        return;
    }

    for (int i = start; i < n; ++i) {
        if (pa[start][i]) {
            path.push_back(s.substr(start, i-start+1));
            dp(s, i + 1, path, result, pa);
            path.pop_back();
        }
    }
   
}

vector<vector<string> > work(const string& s) {
    int n = s.size();
    vector<bool> vf(n, false);
    vector<vector<bool> > palindrome(n, vf);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; j++) {
            if(is_palindrome(s, i, j)) {
                palindrome[i][j] = true;
            }
        }
    }

    vector<string> path;
    vector< vector<string> > result;
    dp(s, 0, path, result, palindrome);
    return result;

}


int main(int argc, const char *argv[])
{
    string a = "aab";
    vector<vector<string> > r1 = partition(a);
    printvv(r1);

    vector<vector<string> > r2 = work(a);
    printvv(r2);

    return 0;
}

