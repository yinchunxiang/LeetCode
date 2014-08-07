#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printvv(vector<vector<char> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(vector<vector<char> > &board, int i, int j, int rows, int cols) {
    board[i][j] = '#';

    //to top 
    if ( i - 1 >= 0 && board[i-1][j] == 'O') {
        dfs(board, i - 1, j, rows, cols);
    }
    //to bottom
    if ( i + 1 < rows && board[i+1][j] == 'O') {
        dfs(board, i + 1, j, rows, cols);
    }
    //to left
    if ( j - 1 >=0 && board[i][j - 1] == 'O') {
        dfs(board, i, j - 1, rows, cols);
    }
    //to right
    if ( j + 1 < cols && board[i][j + 1] == 'O') {
        dfs(board, i, j + 1, rows, cols);
    }
}


void bfs(vector<vector<char> > &board, int i, int j, int rows, int cols) {
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    while(!q.empty()) {
        pair<int,int> point = q.front();
        board[point.first][point.second] = '#';
        q.pop();

        //to top
        if (point.first - 1 >=0 && board[point.first - 1][point.second] == 'O'){
            q.push(make_pair(point.first - 1, point.second));
        }

        // to bottom
        if (point.first + 1 < rows && board[point.first + 1][point.second] == 'O'){
            q.push(make_pair(point.first + 1, point.second));
        }

        // to left
        if (point.second - 1 >=0 && board[point.first][point.second - 1] == 'O'){
            q.push(make_pair(point.first, point.second - 1));
        }

        // to right
        if (point.second + 1 < cols && board[point.first][point.second + 1] == 'O'){
            q.push(make_pair(point.first, point.second + 1));
        }
    }

    printvv(board);
}

void solve(vector<vector<char> > &board) {
    int rows = board.size();
    if (rows < 3) {
        return ;
    }

    int cols = board[0].size();
    if (cols < 3) {
        return;
    }

    for (int j = 0; j < cols; ++j) {
        //top
        if (board[0][j] == 'O') {
            //dfs(board, 0, j, rows, cols);
            bfs(board, 0, j, rows, cols);
        }
    }

    for (int j = 0; j < cols; ++j) {
        //bottom
        if (board[rows - 1][j] == 'O') {
            //dfs(board, rows - 1, j, rows, cols);
            bfs(board, rows - 1, j, rows, cols);
        }
    }

    for (int i = 0; i < rows; ++i) {
        //left
        if(board[i][0] == 'O') {
            //dfs(board, i, 0, rows, cols);
            bfs(board, i, 0, rows, cols);
        }
    }

    for (int i = 0; i < rows; ++i) {
        //right
        if(board[i][cols - 1] == 'O') {
            //dfs(board, i, cols-1, rows, cols);
            bfs(board, i, cols-1, rows, cols);
        }
    }

    for(int i=0;i<rows;i++){  
        for(int j=0;j<cols;j++){  
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }   

            if (board[i][j] == '#') {
                board[i][j] = 'O';
            }

        }
    }

}


int main(int argc, const char *argv[])
{
    /*
    char src[4][4] = {
        {'X','O','x','x'},
        {'O','X','O','x'},
        {'x','O','O','x'},
        {'O','x','X','O'}};
    vector<vector<char> > board;  
    int n = 4;  
    for(int i=0;i<n;i++){  
        vector<char> row;  
        for(int j=0;j<n;j++){  
            row.push_back(src[i][j]);  
            cout << src[i][j];
        }  
        cout << endl;
        board.push_back(row);  
    }  
    cout << endl;

    solve(board);
    printvv(board);

    cout << endl;
    */


    char matrix[5][5] = {
        {'O','X','X','O','X'},
        {'X','O','O','X','O'},
        {'X','O','X','O','X'},
        {'O','X','O','O','O'},
        {'X','X','O','X','O'}
    };

    vector<vector<char> > bd;

    int n = 5;  
    for(int i=0;i<n;i++){  
        vector<char> row;  
        for(int j=0;j<n;j++){  
            row.push_back(matrix[i][j]);  
            cout << matrix[i][j];
        }  
        cout << endl;
        bd.push_back(row);  
    }  
    cout << endl;
    solve(bd);
    printvv(bd);


    return 0;
}
