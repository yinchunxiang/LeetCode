#include <iostream>
#include <vector>
#include <tr1/unordered_map>


using namespace std;
using namespace tr1;


void printvv(vector<vector<int> >& vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl << endl;
}

int dfs(vector<vector<int> >& triangle, int row, int col) {
    if (row >= triangle.size()){
        return 0;
    }


    // down
    int down_sum = dfs(triangle, row + 1, col);

    // down right
    int right_sum = dfs(triangle, row + 1, col + 1);

    //cout << "triangle[" << row <<"][" << col << "] ";
    int ret = triangle[row][col] + min(down_sum, right_sum);
    //cout << ret << endl;


    return ret;
}

/*
int minimumTotal(vector<vector<int> > &triangle) {
    return dfs(triangle, 0, 0);
}
*/

int minimumTotal(vector<vector<int> > &triangle) {
    if (triangle.empty()){
        return 0;
    }

    for (int row = triangle.size() - 2; row >= 0; --row){
        for(int col = triangle[row].size() - 1; col >=0; --col){
             triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
        }
    }

    return triangle[0][0];
}


int main(int argc, const char *argv[])
{
    vector<vector<int> > triangle;
    int a[] = {2};
    vector<int> va(a, a+1);
    triangle.push_back(va);

    int b[] = {3,4};
    vector<int> vb(b, b+2);
    triangle.push_back(vb);

    int c[] = {6,5,7};
    vector<int> vc(c, c+3);
    triangle.push_back(vc);
    
    int d[] = {4,1,8,3};
    vector<int> vd(d, d+4);
    triangle.push_back(vd);

    printvv(triangle);

    cout << minimumTotal(triangle) << endl;
    return 0;
}
