#include <iostream>
#include <vector> 

using namespace std;

void printv(vector<int>& v){ 
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " " ; 
    }
    cout << endl << endl;;
}   

vector<int>  getRow(int rowIndex) {
    vector<int>  result(rowIndex + 1, 1);

    printv(result);

    for (int i = 2; i <= rowIndex; i++) {
        for (int j = i-1; j >= 1; --j) {
            result[j] = result[j-1] + result[j];
        }
    }
    
    return result;
}



int main(int argc, const char *argv[])
{
    vector<int>  v = getRow(3);
    printv(v);
    
    v = getRow(2);
    printv(v);
    return 0;
}

