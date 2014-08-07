#include <iostream>
#include <string>
#include <tr1/unordered_set>
#include <vector> 

using namespace std;
using namespace tr1;

void printv(vector<string>& v){
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

int get_distance(const string& left, const string& right) {
    int ret = 0;
    for (int i = 0; i < left.size(); i++) {
        if (left[i] != right[i]) {
            ret ++;
        }
    }
    return ret;
}


void dfs(const string& start, const string& end, unordered_set<string> dict, int curr, int& min) {
    if (get_distance(start, end) <= 1) {
        curr ++;
        cout << "curr:" << curr << endl << endl;
        cout << "min:" << min << endl << endl;
        if (curr < min) {
            min = curr;
            cout << "newmin:" << min << endl << endl;
        }
        return;
    }

    if (dict.empty()) {
        return;
    }

    unordered_set<string>::iterator it = dict.begin();
    for(; it != dict.end(); ++it) {
        if (get_distance(start, *it) <= 1 && curr < min) {
            unordered_set<string> temp = dict;
            temp.erase(*it);
            dfs(*it, end, temp, curr + 1, min);
        }
    }
}

int ladderLength(string start, string end, unordered_set<string> &dict) {
    int min = dict.size() + 3;
    int curr = 1;
    unordered_set<string>::iterator it = dict.begin();
    dfs(start, end, dict, curr, min);
    if (min >= dict.size() + 3) {
        return 0;
    }
    return min;
}

int main(int argc, const char *argv[])
{
    string a[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> dict(a, a + 5);
    cout << ladderLength("hit", "cog", dict) << endl;
    return 0;
}

