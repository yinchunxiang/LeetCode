#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void printvv(vector< vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

void setZeroes(vector<vector<int> > &matrix) {
    int nrow = matrix.size();
    if (0 == nrow) return;
    int ncol = matrix[0].size();
    int row = -1;
    int col = -1;

    for (int i = 0; i < nrow; ++i) {
        for (int j = 0; j < ncol; ++j) {
            if (0 == matrix[i][j]) {
                if (-1 == row && -1 == col){ row = i; col = j; }
                else { matrix[i][col] = 0; matrix[row][j] = 0; }
            }
        }
    }
    if (-1 == row || -1 == col) return;
    // set zero
    for (int i = 0; i < nrow; ++i){
        if (i == row) {
            continue;
        }
        for (int j = 0; j < ncol; ++j) {
            if ( j == col) {
                continue;
            }
            if (0 == matrix[row][j] || 0 == matrix[i][col]){
                matrix[i][j] = 0;
            }
        }
    }
    fill(&matrix[row][0], &matrix[row][0] + ncol, 0);
    for ( int i = 0; i < nrow; ++i) { matrix[i][col] = 0; }

    return;
}



int main(int argc, const char *argv[])
{
    int a[5][4] = {
        {0,0,0,5},
        {4,3,1,4},
        {0,1,1,4},
        {1,2,1,3},
        {0,0,1,1}};
    vector< vector<int> > input;
    for (int i = 0; i < 5; ++i) {
        input.push_back(vector<int>(&a[i][0], &a[i][0] + 4));
    }
    printvv(input);
    setZeroes(input);
    printvv(input);

    return 0;
}


