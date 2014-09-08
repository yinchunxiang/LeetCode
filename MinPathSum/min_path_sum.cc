#include <vector> 
#include <iostream> 

using namespace std;

void printv(vector<int>& v){ 
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " " ; 
    }
    cout << endl << endl;;
}   


int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int row = obstacleGrid.size();
    if (0 == row) return 0;
    int col = obstacleGrid[0].size();
    vector<int> f(col, 0);
    f[0] = (1 == obstacleGrid[0][0]) ? 0 : 1;
    cout << "f[0]: " << f[0] << endl;
    for (int i = 1; i < col; ++i) {
        if (1 == obstacleGrid[0][i]) {
            f[i] = 0;
        }
        else {
            f[i] = f[i -1];
        }
        cout << "f[" << i << "]: " << f[i] << endl;
    }

    for (int i = 1; i < row; ++i) {
        if (1 == obstacleGrid[i][0]) {
            f[0] = 0;
        }
        for (int j = 1; j < col; ++j) {
            f[j] = (1 == obstacleGrid[i][j]) ? 0 : f[j] + f[j - 1];
        }
        cout << "f[" << i << "]: " << f[i] << endl;
    }

    return f[col - 1];
}


int main(int argc, const char *argv[])
{
    int a[2][1] = {{0},{1}};
    vector<vector<int> > vv;
    for (int i = 0; i < 2; ++i) {
        vector<int> v(&a[i][0], &a[i][1]);
        vv.push_back(v);
    } 

    cout << uniquePathsWithObstacles(vv) << endl;

    return 0;
}
