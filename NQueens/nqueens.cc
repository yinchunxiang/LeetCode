#include <iostream>
#include <vector>

using namespace std;

void printvv(vector< vector<string> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << vv[i][j] << " "  << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int n, int level, vector<bool> & used_col, vector<bool>& used_main_diagonal, vector<bool>& used_anti_diagonal,
        vector<string>& sub, vector< vector<string> > & result) {
    if (level >= n) { result.push_back(sub); return; }
    for( int i = 0; i < n; ++i) {
        if (!used_col[i] && !used_main_diagonal[level + i] && !used_anti_diagonal[n - 1 + level - i])  {
            string a(n, '.');
            a[i] = 'Q';
            sub.push_back(a);
            used_col[i] = true;
            used_main_diagonal[i + level] = true;
            used_anti_diagonal[n - 1 + level - i] = true;
            dfs(n, level + 1, used_col, used_main_diagonal, used_anti_diagonal, sub, result);
            used_col[i] = false;
            used_main_diagonal[i + level] = false;
            used_anti_diagonal[n - 1 + level - i] = false;
            sub.pop_back();
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > result;
    if (0 == n) { return result; }
    vector<bool> used_col(n, false);
    vector<bool> used_main_diagonal(2 * n - 1, false);
    vector<bool> used_anti_diagonal(2 * n - 1, false);
    
    vector<string> sub;
    dfs(n, 0, used_col, used_main_diagonal, used_anti_diagonal, sub, result); 
    return result;
}

int main(int argc, const char *argv[])
{
    vector<vector<string> > vv = solveNQueens(4);
    printvv(vv);
    return 0;
}
