#include <iostream>
#include <vector>

using namespace std;

void printvv(vector< vector<int> > & vv) {
    vector< vector<int> >::iterator it = vv.begin();
    for (; it != vv.end(); ++it) {
        vector<int>::iterator jt = it->begin();
        for(; jt != it->end(); ++jt) {
            cout << *jt << " ";
        }
        cout << endl;
    }
}

void genset(int n , int level, vector<int> sub, vector< vector<int> > &result) {
    if (level > n) {
        result.push_back(sub);
        return;
    }

    genset(n, level + 1, sub, result);
    sub.push_back(level);
    genset(n, level + 1, sub, result);
}

vector< vector<int> > get_set(int n) {
    vector< vector<int> > ret;
    vector<int> sub;
    genset(n, 1, sub, ret);
    return ret;
}



int main() {
    vector< vector<int> > ret = get_set(3);
    printvv(ret);
    return 0;
}
