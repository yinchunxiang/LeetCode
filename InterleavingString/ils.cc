#include <iostream> 
#include <vector> 

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }
    vector<bool> col(s2.size() + 1, true);
    vector< vector<bool> > vv(s1.size() + 1, col);

    for(int j = 1; j < s2.size() + 1; ++j) {
        vv[0][j] = vv[0][j - 1] && s2[j-1] == s3[j-1];
    }

    for(int i = 1; i < s1.size() + 1; ++i) {
        vv[i][0] = vv[i - 1][0] && s1[i - 1] == s3[i - 1];
    }
    
    for(int i = 1; i < vv.size(); ++i) {
        for(int j = 1; j < vv[i].size(); ++j){
            bool con1 = vv[i-1][j] && s1[i-1] == s3[i+j-1];
            bool con2 = vv[i][j-1] && s2[j-1] == s3[i+j-1];
            vv[i][j] = con1 || con2;
            cout << "vv[" << i << "][" << j << "]: " << vv[i][j] << endl;
        }
    }
    return vv[s1.size()][s2.size()];
}

int main(int argc, const char *argv[])
{
    string s1 = "aa";
    string s2 = "ab";
    string s3 = "aaba";
    cout << "s1 => " << s1 << endl;
    cout << "s2 => " << s2 << endl;
    cout << "s3 => " << s3 << endl;
    cout << isInterleave(s1, s2, s3) << endl;

    return 0;
}


