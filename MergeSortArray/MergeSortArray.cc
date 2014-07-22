#include <iostream>

using namespace std;


void merge(int A[], int m, int B[], int n) {
    int i = m -1;
    int j = n -1;
    int index = m+n-1;
    for(; index>=0; --index ) {
        if ( i < 0 || j < 0) {
            break;
        }
        if (A[i] > B[j] ) {
            A[index] = A[i--];
        }
        else {
            A[index] = B[j--];
        }
    }

    if (i < 0) {
        for (; j>=0; j--) {
            A[index--] = B[j];
        }
    }

}

int main(int argc, const char *argv[])
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int b[5] = {20,21,22,23,24};
    merge(a,5,b,5);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << endl;
    }

    int c[1] = {0};
    int d[1] = {1};
    merge(a,0,b,1);
    for (int i = 0; i < 1; i++) {
        cout << c[i] << endl;
    }

    return 0;
}

