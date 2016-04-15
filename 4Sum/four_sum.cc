#include <vector>
#include <iostream>
#include <unordered_map> 

using namespace std;

void printv(vector<int>& v){ 
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " " ; 
    }
    cout << endl << endl;;
}   

void printvv(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " " ; 
        }
        cout << endl;
    }   
    cout << endl ;
}


vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    int n = num.size();
    if (n < 4) { return result; }

    sort(num.begin(), num.end());
    unordered_map<int, vector<pair<int, int> > > cache;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && num[i - 1] == num[i]) continue;
        for (int j = i + 1; j < n; ++j) {
            if (j > i + 1 && num[j - 1] == num[j]) continue;
            cout << num[i] + num[j]  << endl;
            cache[num[i] + num[j]].push_back(pair<int, int>(i, j));
        }
    }
    
    vector<int> temp(4, 0);
    for (int c = 0; c < n; ++c) {
        //if (c > 0 && num[c - 1] == num[c]) { continue; }
       for (int d = c + 1; d < n; ++d) {
            //if (d > c + 1 && num[d - 1] == num[d]) { continue; }
            const int key = target - num[c] - num[d];
            if (cache.find(key) == cache.end()) continue;
            //cout << "key: " << key << endl;
            //cout << "(c, d) => (" << c << "," << d << ")" << endl;
            const vector<pair<int, int> >& vec = cache[key];
            for (int k = 0; k < vec.size(); ++k) {
                if (c <= vec[k].second) continue;  //overlap, insure a < b < c < d
                temp[0] = num[vec[k].first];
                temp[1] = num[vec[k].second];
                temp[2] = num[c];
                temp[3] = num[d];
                if (result.empty() || temp != result.back()) {
                    result.push_back(temp);
                }
            }
        }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    return result;
}

int main(int argc, const char *argv[])
{
    {
        int a[] = {-3,-2,-1,0,0,1,2,3};
        vector<int> v(a, a + 8);
        vector<vector<int> > result = fourSum(v, 0) ;
        printvv(result);
    }
    /*
    {
        int a[] = {0, 0, 0, 0};
        vector<int> v(a, a + 4);
        vector<vector<int> > result = fourSum(v, 0) ;
        printvv(result);
    }
    */
    return 0;
}
