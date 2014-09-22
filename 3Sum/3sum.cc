#include <vector> 
#include <iostream> 
#include <iterator> 
#include <algorithm> 


using namespace std;

void printvv(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " " ; 
        }
        cout << endl;
    }   
    cout << endl ;
}

vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    int n = num.size();
    if (n < 3) { return result; }
    sort(num.begin(), num.end());
    vector<int> temp(3, 0);
    for (int i = 0; i < n - 2; ++i) {
        int a = i; int b = i + 1; int c = n - 1;
        int sum = num[a] + num[b] + num[c];
        while (b < c) {
            if (sum < 0) {
                ++b;
            }
            else if (sum > 0) {
                --c;
            }
            else {
                temp[0] = num[a]; temp[1] = num[b]; temp[2] = num[c];
                if (result.empty() || temp != result.back()) {
                result.push_back(temp);
                }
                ++b; --c;
            }
        }
    }
    return result;
}

int main(int argc, const char *argv[]) {
    int a[] = {3,0,-2,-1,1,2};
    vector<int> v(a, a + 6);
    vector<vector<int> > vv = threeSum(v);
    printvv(vv);
    return 0;
}
