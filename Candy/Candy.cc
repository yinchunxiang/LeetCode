#include <iostream>
#include <vector>
#include <numeric> //accumulate

using namespace std;

void printv(vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] ;
    }
    //cout << "==================" << endl;
}

int candy(vector<int> &ratings) {
    int n = ratings.size();

    vector<int> ca(n,1);

    //注意更新的方向，最终要保证更新方向与i的递增/递减方向一致
    //
    //先跟当前元素右边的比较
    for(int i = 1; i < n ; ++i) {
        if (ratings[i] > ratings[i-1]) {
            ca[i] = max(ca[i], ca[i - 1] + 1);
        }
    }


    //再跟当前元素左边的比较
    for(int i = n-2 ; i>=0; --i) {
        if (ratings[i] > ratings[i+1]) {
            ca[i] = max(ca[i], ca[i+1] + 1);
        }
    }


    return accumulate(ca.begin(), ca.end(), 0);
}

int main() {
    int a[] = {2, 1};
    vector<int> vec(a, a+2);
    cout << "input: {" ;
    printv(vec);
    cout <<  "}" << endl;
    cout << candy(vec) << endl;

    int b[] = {1,3,5};
    vector<int> vb(b, b+3);
    cout << "input: {" ;
    printv(vb) ;
    cout <<  "}" << endl;
    cout << candy(vb) << endl;

    int c[] = {5,3,1};
    vector<int> vc(c, c+3);
    cout << "input: {" ;
        printv(vc);
        cout <<  "}" << endl;
    cout << candy(vc) << endl;
}
