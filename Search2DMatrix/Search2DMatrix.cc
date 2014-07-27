#include <iostream>
#include <vector>

using namespace std;

bool search_2d_matrix(vector<vector<int> >& matrix, int target ) {
    if (matrix.size() <= 0) {
        return false;
    }
    int row = matrix.size();
    cout << "row:" << row << endl;
    int column = matrix[0].size();
    cout << "column:" << column << endl;
    vector< vector<int> >::iterator it = matrix.begin();
    int low = 0;
    int high = row * column -1;
    while (low <= high) {
        //int mid = (low + high) / 2;
        int temp = (high - low) >> 1;
        cout << "temp:" << temp << endl;
        int mid = low + ((high - low) >> 1);
        cout << "low:" << low << endl;
        cout << "high:" << high << endl;
        cout << "mid:" << mid << endl;
        int i = mid / column;
        int j = mid % column;
        if (target == matrix[i][j]) {
            return true;
        }

        if (target > matrix[i][j]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main(int argc, const char *argv[])
{
    vector<vector<int> > matrix;
    int a[] = {1, 1};
    vector<int> avec(a, a + 2);
    matrix.push_back(avec);
    cout << search_2d_matrix(matrix, 2) << endl;
    return 0;
}
