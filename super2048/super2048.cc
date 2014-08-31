#include <iostream>
#include <string> 
#include <vector> 

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


int main(int argc, const char *argv[])
{
    int num_test_case = 0;
    cin >> num_test_case;
    cout << "Test Number: " << num_test_case << endl;
    for (int i = 0; i < num_test_case; ++i) {
        int board = 0;
        string dir;
        cin >> board >> dir;
        cout << board << " " << dir << endl;
        vector<int> v(board, 0);
        vector< vector<int> > vv(board, v);
        for (int i = 0; i < board; ++i){
            for(int j = 0; j < board; ++j) {
                cin >> vv[i][j];
                cout << vv[i][j] << " "; 
            }
            cout << endl;
        }

        if (dir == "up"){
            cout << "direct is " << dir << endl;
            for(int col = 0; col < board; ++col){
                int count = 0;
                int prev = 0;
                int index = 0;
                for (int row = 0; row < board; ++row){
                    if (count == 1) {
                        if (vv[row][col] == 0) continue;
                        if (prev == vv[row][col]){
                            vv[row][index - 1] += vv[row][col];
                            count = 0;
                        }
                        else {
                            vv[row][index++] = vv[row][col];
                            prev = vv[row][col];
                        }
                        continue;
                    }
                    if (count == 0) {
                        if (vv[row][col]) {
                            prev = vv[row][col];
                            vv[row][index++] = vv[row][col];
                            count = 1;
                        }
                        continue;
                    }
                }
            }

            printvv(vv);
        }

        if (dir == "down"){
            cout << "direct is " << dir << endl;
        }

        if (dir == "left" || dir == "right") {
            int begin, end, step;
            if (dir == "left") {
                begin = 0;
                end = board;
                step = 1;
            }
            else {
                begin = board - 1;
                end = -1;
                step = -1;
            }

            for(int row = 0; row < board; row ++){
                int prev = 0;
                int count = 0;
                int index = begin;
                for (int col = begin; col != end; col += step) {
                    if (vv[row][col] == 0) continue;
                    if (count == 0) {
                        prev = vv[row][col];
                        if (index != col) {
                            vv[row][index] = vv[row][col];
                            vv[row][col] = 0;
                        }
                        index += step;
                        count = 1;
                    }
                    else {
                        if ( prev == vv[row][col] ) {
                            vv[row][index + step] += vv[row][col];
                            vv[row][col] = 0;
                            count = 0;
                        }
                        else {
                            prev = vv[row][col];
                            if (col != index) {
                                vv[row][index] = vv[row][col];
                                vv[row][col] = 0;
                            }
                            index += step;
                        }
                    }
                }
            }
            printvv(vv);
        }


    }



    return 0;
}


