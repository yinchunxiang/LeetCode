#include <iostream>
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

vector<vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    for (int i = 0; i < numRows; i++) {
        vector<int> v(i+1, 1);
        result.push_back(v);
    }

    printvv(result);

    for (int i = 2; i < numRows; i++) {
        for (int j = 1; j < i; ++j) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    
    return result;
}



int main(int argc, const char *argv[])
{
    vector<vector<int> > vv = generate(5);
    printvv(vv);
    
    return 0;
}

