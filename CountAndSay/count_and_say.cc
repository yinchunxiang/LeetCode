#include <string>
#include <iostream>
#include <sstream>


using namespace std;


string countAndSay(int n) {
    string ret = "1";
    if (n <= 1) {
        return ret;
    }

    for (int i = 1; i < n; ++i) {
        int count = 0;
        stringstream newret;
        for (int j = 0; j < ret.size(); ++j) {
            if (0 == j) { 
                count = 1;
            }
            else if (ret[j] != ret[j -1]) {
                newret << count << ret[j - 1];
                count = 1;
            }
            else {
                count ++;
            }
        }
        newret << count << ret[ret.size() - 1];
        ret = newret.str();
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    cout << countAndSay(1) << endl; 
    cout << countAndSay(2) << endl; 
    cout << countAndSay(3) << endl; 
    cout << countAndSay(4) << endl; 
    cout << countAndSay(5) << endl; 
    return 0;
}
