#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(vector<vector<char> > &board, int x, int y, vector<vector<bool> >& used, string sub, const string& word) {
    if (sub.size() >= word.size()) return true;
    if ( x < 0 || x >= board.size() ) return false;
    if (y < 0 || y >= board[x].size()) return false;
    char curr = word[sub.size()];
    if (board[x][y] != curr) {
        return false;
    }
    if (used[x][y]) {
        return false;
    }
    used[x][y] = true;
    sub.push_back(curr);
    bool ret =  dfs(board, x - 1, y, used, sub, word)
        || dfs(board, x + 1, y, used, sub, word)
        || dfs(board, x, y - 1, used, sub, word)
        || dfs(board, x, y + 1, used, sub, word);
    used[x][y] = false;
    return ret;
}

bool exist(vector<vector<char> > &board, string word) {
    if (board.empty() && word.empty()) return true;
    if (board.empty()) return false;
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool> > used( row, vector<bool>(col, false) );
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (dfs(board, i, j, used, "", word)){
                return true;
            }
        }
    }
    return false;
}

void printvv(vector< vector<char> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
    string arr[] = {"a"};
    vector<string> a(arr, arr + 1);
    vector<vector<char> > vv;
    for (int i = 0; i < a.size(); ++i) {
        vector<char> v(&a[i][0], &a[i][0] + a[i].size());
        vv.push_back(v);
    }
    printvv(vv);
    cout << exist(vv, "a") << endl;
    return 0;
}


