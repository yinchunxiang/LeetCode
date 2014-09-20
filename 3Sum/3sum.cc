#include <vector> 
#include <iostream> 
#include <iterator> 

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
    if (n < 3) {
        return result;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < n - 2; ++i) {
        int a = num[i];
        int b = num[i + 1];
        int c = num[n - 1];
        while (b < c) {
            if (a + b + c < 0) {
                ++b;
            }
            else if (a + b + c > 0) {
                --c;
            }
            else {
                vector<int> temp;
                temp.push_back(a);
                temp.push_back(b);
                temp.push_back(c);
                result.push_back(temp);
                ++b;
                --c;
            }
        }
    }
    sort(result.begin(), result.end());
    printvv(result);
    int rn = result.size();
    if (rn <= 1) { return result;}

    vector<vector<int> >::iterator prev = result.begin();
    vector<vector<int> >::iterator it = ++prev;
    while (it != result.end()) {
        if (*it != *prev) {
            ++it;
        }
        else {
            result.erase(it++);
            ++prev;
        }
    }
    return result;
}



int main(int argc, const char *argv[]) {
    int a[] = {-1,-1,-1,1};
    vector<int> v(a, a + 4);
    vector<vector<int> > vv = threeSum(v);
    printvv(vv);
    return 0;
}
