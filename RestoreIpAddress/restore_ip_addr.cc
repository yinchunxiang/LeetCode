#include <iostream> 
#include <vector>
#include <string>
#include <tr1/unordered_set>

using namespace std;
using namespace tr1;

void printv(vector<string>& v) {
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
    cout << endl;
}



void restore_ip_addr(const string& s, vector<string>& result, int level, int start,  string sub) {
    if (level >= 4 && start == s.size()) {
        sub.resize(sub.size() - 1);
        result.push_back(sub);
        return;
    }

    // pruning 剪枝
    if (s.size() - start > (4 - level) * 3 ) return;
    if (s.size() - start < 4 - level) return;

    int number = 0;
    for (int i = start ; i < start + 3; ++i) {
        number = number* 10 + s[i] - '0';
        if (number < 256) {
            sub += s[i];
            restore_ip_addr(s, result, level + 1, i + 1, sub + ".");
        }

        if (0 == number) {
            break;
        }
    }

}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    restore_ip_addr(s, result, 0, 0, "");
    return result;
}

int main(int argc, const char *argv[])
{
    string s = "25525511135";
    vector<string> result = restoreIpAddresses(s);
    printv(result);

    s = "0000";
    result = restoreIpAddresses(s);
    printv(result);


    return 0;
}

