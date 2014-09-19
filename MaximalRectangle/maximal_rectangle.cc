#include <vector>
#include <iostream>
#include <stack>


using namespace std;

void printvvi(vector< vector<int> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}


int maximalRectangle(vector<vector<char> > &matrix) {
    vector< vector<int> > histogram;
    
    for (int i = 0; i < matrix.size(); i++) {
        int n = matrix[i].size();
        vector<int> v(n + 1);
        histogram.push_back(v);
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (matrix[i][j] == '1') {
                    histogram[i][j] = 1;
                }
                else {
                    histogram[i][j] = 0;
                }
            }
            else if (matrix[i][j] == '1' && matrix[i - 1][j] == '1') {
                histogram[i][j] = histogram[i - 1][j] + 1;
            }
            else if (matrix[i][j] == '1') {
                histogram[i][j] = 1;
            }
            else {
                histogram[i][j] = 0;
            }
        }
    }

    printvvi(histogram);

    int max_rectangle = 0;
    for (int i = 0; i < histogram.size(); i++) {
        stack<int> s;
        int n = histogram[i].size();
        for (int j = 0; j < n; j++) {
            if (s.empty() || histogram[i][j] >= histogram[i][s.top()]) {
                s.push(j);
            }
            else {
                int index = s.top();
                s.pop();
                int w = s.empty() ? j  : j - s.top() - 1;
                int h = histogram[i][index];
                int area = w * h;
                cout << "area: " << area << endl;
                max_rectangle = area > max_rectangle ? area : max_rectangle;
                cout << "max_rectangle: " << max_rectangle << endl;
                j --;
            }
        }
    }

    return max_rectangle;
}

void printvv(vector< vector<char> >& vv) {
    for (int i = 0; i < vv.size(); ++i) {
        for (int j = 0; j < vv[i].size(); ++j){
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    {
        vector<vector<char> > vv;
        string s[] = {
            "00010111",
            "01100101",
            "10111101",
            "00010000",
            "00100010",
            "11100111",
            "10011001",
            "01001100",
            "10010000"};
        for (int i = 0; i < 9; i++) {
            vector<char> v(&s[i][0], &s[i][8]);
            vv.push_back(v);
        }
        printvv(vv);

        cout << maximalRectangle(vv) << endl;
    }

    {

        vector<vector<char> > vv;
        string s[] = {"01101","11010","01110","11110","11111","00000"};
        for (int i = 0; i < 6; i++) {
            vector<char> v(&s[i][0], &s[i][5]);
            vv.push_back(v);
        }
        printvv(vv);

        cout << maximalRectangle(vv) << endl;
    }

    return 0;

}


