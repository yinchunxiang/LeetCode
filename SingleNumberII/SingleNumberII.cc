#include <iostream>

using namespace std;


int singleNumber(int A[], int n) {
    int count[32] = {0};

    for(int i = 0; i<n; ++i) {
        for(int j = 0; j < 32 && A[i]; ++j) {
            count[j] = (count[j] + (A[i] & 1)) % 3;
            A[i] >>= 1;
            cout << A[i] << endl;
        }
    }

    for( int i = 0; i < 32; ++i) {
        if (count[i]) {
            cout << "count[" <<i <<"] = " << count[i] << endl;
        }
    }

    int ret = 0;
    for( int i=0; i<32; ++i) {
        if(count[i] % 3 != 0) {
            ret |= (count[i] << i);
        }
    }

    return ret;
}


int main() {
    int a[] = {2,3,2,2};
    cout << singleNumber(a, 4) << endl;
    return 0;
}
