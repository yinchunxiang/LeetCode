#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
    vector<int> v(n, 0);
    vector<vector<int> > vv(n, v);
    int status = 0;
    int step = 0;
    int min_row = 0; 
    int max_row = n - 1;
    int min_col = 0;
    int max_col = n - 1;
    int count = n * n;
    int x = 0;
    int y = 0;
    while (step++ < count) {
        vv[x][y] = step;
        printf("v[%d][%d]:%d\n", x, y, vv[x][y]);
        switch (status) {
            case 0:
                if (y < max_col) {
                    y += 1;
                }
                else {
                    min_row += 1;
                    x += 1;
                    status = (status + 1) % 4;
                }
                break;
            case 1:
                if (x < max_row) {
                    x += 1;
                }
                else {
                    max_col -= 1;
                    y -= 1;
                    status = (status + 1) % 4;
                }
                break;
            case 2:
                if (y > min_col) {
                    y -= 1;
                }
                else {
                    max_row -= 1;
                    x -= 1;
                    status = (status + 1) % 4;
                }
                break;
            case 3:
                    if (x > min_row) {
                        x -= 1;
                    }
                    else {
                        min_col += 1;
                        y += 1;
                        status = (status + 1) % 4;
                    }
                break;
        }
    }

    return vv;
}

void printvv(vector< vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << setw(5) << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
     vector<vector<int> > vv = generateMatrix(4);
     printvv(vv);
    return 0;
}
