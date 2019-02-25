#include <vector>
#include <iostream>

using namespace std;



void dfs(int n, int k, int start, vector<int> sub, vector<vector<int> > &result){
    if (sub.size() >= k) {
        result.push_back(sub);
        return;
    }

    if (start > n) {
        return;
    }

    dfs(n, k, start + 1, sub, result);
    sub.push_back(start);
    dfs(n, k, start + 1, sub, result);
}


vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > result;
    if (n < k) { return result;}
    vector<int> v;
    dfs(n, k, 1, v, result);
    return result;
}

void printvv(vector< vector<int> >& vv) {
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
     vector<vector<int> > vv = combine(4, 2);
     printvv(vv);
     
    return 0;
}
