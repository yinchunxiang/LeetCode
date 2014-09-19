#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> &num, int gap, int start, vector<int> &temp, vector<vector<int> > &result) {
    if (0 == gap) {
        result.push_back(temp);
        return;
    }

    for (int i = start; i < num.size(); ++i) {
        if (i >= 1 && num[i] == num[i - 1]) {
            continue;
        }
        if (gap < num[i]) {
            continue;
        }
        else {
            gap -= num[i];
            temp.push_back(num[i]);
            dfs(num, gap, i + 1, temp, result);
            gap += num[i];
            temp.pop_back();
        }
    }
}


vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > result;
    vector<int> temp;
    sort(num.begin(), num.end());
    dfs(num, target, 0, temp, result);
    return result;
}

void printvv(vector< vector<int> > &vv) {
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
    int a[] = {10,1,2,7,6,1,5};
    vector<int> v(a, a + 7);
    vector<vector<int> > result = combinationSum2(v, 8);

    printvv(result); 
    
    return 0;
}
