#include <vector> 
#include <iostream> 

using namespace std;


string convert(string s, int nRows) {
    int n = s.size();
    vector<string> v(nRows, "");    
    for (int i = 0; i < n; ) {
        for (int j = 0; j < nRows && i < n; ++j) {
            v[j].push_back(s[i++]);
        }
        if (i >= n) {
            break;
        }
        for (int j = nRows - 2; j >= 1 && i < n; --j) {
            v[j].push_back(s[i++]);
        }
    }

    string result;
    for (int i = 0; i < nRows; ++i) {
        result += v[i];
    }
    return result;
}

int main(int argc, const char *argv[])
{
    {
    string s = "PAYPALISHIRING";
    cout << convert(s, 3) << endl;
    }
    {
    string s = "ABCDE";
    cout << convert(s, 4) << endl;
    }
    return 0;
}
