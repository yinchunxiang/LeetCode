#include <iostream>

using namespace std;

int remove_dup(int A[], int n){
    int start = 0;
    int end = 0;
    int dup = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == A[start]) {
            dup += 1;
        }
        else {
            start = i;
            dup = 1;
        }
        if (dup <= 2) {
            A[end ++] = A[i];
        }
    }
    return end;
}


int main(int argc, const char *argv[])
{
    int input[] = {1,1,1,2,2,3}; 
    cout << remove_dup(input, 6) << endl;
    return 0;
}


