#include <iostream>
#include <vector> 

using namespace std;

vector<char> solve(int n, int k) {
    vector<char> result;
    //vector<int> v(n + 1, 0);
    vector<vector<int> > vv(n + 1, vector<int>(n + 1, 0));
    vv[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (1 == i && 1 == j) continue;
            if (i > j) {
                vv[i][j] = vv[i - 1][j];
            }
            else {
                vv[i][j] = vv[i - 1][j] + vv[i][j - 1];
            }
        }
    }

    result.push_back('(');
    int left = n; 
    int right = n;
    while (k > 0) {
        if (vv[left][right] >= k) {
            result.push_back('(');
            if (vv[left - 1][right] >= k) {
                result.push_back('(');
                left -= 1;
            }
            else {
                result.push_back(')');
                right -= 1;
            }
        }
        else {
            return result;        
        }
    }


    
    cout << vv[n][n] << endl;
    return result;
}


int main(int argc, const char *argv[])
{
    solve(3);    
    return 0;
}



