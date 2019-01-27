#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<int> &candidates, int target, int start, vector<int> &sub, int subsum, vector<vector<int> >& result) {
    for (int i = start; i < candidates.size(); ++i) {
        int tempsum = subsum + candidates[i];
        if (tempsum > target) {
            return;
        }

        if (tempsum == target) {
            sub.push_back(candidates[i]);
            result.push_back(sub);
            sub.pop_back();
            continue;
        }
       
        sub.push_back(candidates[i]);
        subsum = tempsum;
        dfs(candidates, target, i, sub, subsum, result);
        sub.pop_back();
        subsum -= candidates[i];
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > result;
    vector<int> sub;
    dfs(candidates, target, 0, sub, 0, result);
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
    int a[] = {2,3,6,7};
    vector<int> v(a, a + 4);
    vector<vector<int> > vv = combinationSum(v, 7);
    printvv(vv);
    
    return 0;
}
