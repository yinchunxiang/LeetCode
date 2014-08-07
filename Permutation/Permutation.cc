#include <iostream>
#include <vector> 

using namespace std;


void helper(vector<int>& num, vector<int> sub, vector< vector<int> >& retset, vector<int> used) {
    if (sub.size() >= num.size()) {
        retset.push_back(sub);
        return;
    }

    int pre_index = -1;
    for(int i = 0; i<used.size(); ++i) {
        if (!used[i] && (pre_index == -1|| num[pre_index] != num[i])) {
            sub.push_back(num[i]);
            used[i] = 1;
            helper(num, sub, retset, used);
            sub.pop_back();
            used[i] = 0;
            pre_index = i;
        }
    }
}

vector<vector<int> > permute(vector<int> &num) {
    vector< vector<int> > ret;
    vector<int> used(num.size(), 0);
    vector<int> sub;
    helper(num, sub, ret, used);
    return ret;
}

void print_result(vector< vector<int> >& result) {
    vector< vector<int> >::iterator iti = result.begin();
    for(; iti != result.end(); ++iti) {
        vector<int>::iterator itj = iti->begin();
        cout << "[ " ;
        for(; itj != iti->end(); ++itj) {
            cout << *itj << " ";
        }
        cout << "]" << endl;
    } 
}

int main(int argc, const char *argv[])
{
    int a[] = {1,2,3};
    vector<int> vec(a, a+3);
    vector< vector<int> > result = permute(vec);
    print_result(result);

    cout << "======================" << endl;
    int b[] = {1,1,2};
    vector<int> vb(b, b+3);
    result = permute(vb);
    print_result(result);

    cout << "======================" << endl;
    int c[] = {1,2,1};
    vector<int> vc(c, c+3);
    result = permute(vc);
    print_result(result);
    return 0;
}

