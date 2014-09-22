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


bool vec_comp(const vector<int> &lhs, const vector<int> &rhs) {
    int ln = lhs.size();
    int rn = rhs.size();
    if (ln != rn) {
        return false;
    }

    int i = 0;
    for (; i < ln && i < rn; ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }

    if (i < ln || i < rn) {
        return false;
    }

    return true;
}

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    int n = num.size();
    if (n < 4) { return result; }

    sort(num.begin(), num.end());
    unordered_map<int, vector<pair<int, int> > > cache;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cache[num[i] + num[j]].push_back(pair<int, int>(i, j));
        }
    }
    
    vector<int> temp(4, 0);
    for (int c = 0; c < n; ++c) {
        cout << "aaa" << endl;
        if (c > 0 && num[c - 1] == num[c]) { continue; }
       for (int d = c + 1; d < n; ++d) {
cout << "bbbb" << endl;
            if (d > c + 1 && num[d - 1] == num[d]) { continue; }
            const int key = target - num[c] - num[d];
            if (cache.find(key) == cache.end()) continue;
            const vector<pair<int, int> >& vec = cache[key];
            for (int k = 0; k < vec.size(); ++k) {
cout <<" bbbb ===> ccc" << endl;
                if (c <= vec[k].second) continue;  //overlap, insure a < b < c < d
                temp[0] = num[vec[k].first];
                temp[1] = num[vec[k].second];
                temp[2] = num[c];
                temp[3] = num[d];
                printv(temp);
cout <<" yyyyyyy" << endl;
                if (!vec_comp(temp, result.back())) {
                    result.push_back(temp);
                }
            }
cout << "ccc" << endl;
        }
    }
    
    return result;
}

int main(int argc, const char *argv[])
{
    {
        int a[] = {2,1,0,-1};
        vector<int> v(a, a + 4);
        vector<vector<int> > result = fourSum(v, 2) ;
        cout << "xxxxx" << endl;
        printvv(result);
    }
    return 0;
}
