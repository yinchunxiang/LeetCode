#include <vector>
#include <string>
#include <iostream>



using namespace std;

void printvv(vector< vector<char> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

bool valid(vector<vector<char> > &board, int x, int y) {
    for (int i = 0; i < 9; ++i) {
        if (i != y && board[x][y] == board[x][i] ) {
            return false;
        }

        if (i != x && board[x][y] == board[i][y]) {
            return false;
        }
    }

    for (int i = 3 *(x/3); i < 3*(x/3 + 1); ++i) {
        for (int j = 3*(y/3); j < 3*(y/3 + 1); ++j) {
            if ((i != x || j != y) && board[x][y] == board[i][j]) {
                return false;
            }
        }
    }
    return true;
}



bool solve_sudoku(vector<vector<char> > &board, int x, int y) {
    //cout << "=======> x: " << x << " y: " << y << endl;
    //printvv(board);
    for (int i = x; i < 9; ++i) {
        for (int j = y; j < 9; ++j) {
            if ('.' != board[i][j]) {
                continue;
            }
            for (int k = 0; k < 9; ++k){
                board[i][j] = '1' + k;

                if (valid(board, i, j) && solve_sudoku(board, i, j)){ 
                    return true;
                }
                else {
                    board[i][j] = '.';
                }
            }
            //printvv(board);
            return false;
        }
        y = 0;
    }
    return true;
}



int main(int argc, const char *argv[])
{
    string a[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char> > board;
    for (int i = 0; i < 9; ++i) {
        vector<char> temp;
        for (int j = 0; j < 9; ++j) {
            temp.push_back(a[i][j]);
        }
        board.push_back(temp);
    }
    printvv(board);
    cout << solve_sudoku(board, 0, 0) << endl;
    printvv(board);
    return 0;
}
