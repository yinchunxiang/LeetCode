#include <iostream> 

using namespace std;


void sortColors(int A[], int n) {
    int rindex = 0;
    int bindex = n - 1;
    for (int i = rindex; i <= bindex; ++i) {
        if (A[i] == 0) {
            swap(A[rindex++], A[i]);
        }
        else if (A[i] == 2) {
            swap(A[bindex--], A[i]);
            i --;
        }
    }
}

void partition(int A[], int n, int pivot){
    int end = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] <= pivot){
            swap(A[end], A[i]);
            end ++;
        }
    }
}

void printv(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << v[i] << endl;
    }
    cout << endl;
}


int main(int argc, const char *argv[])
{
    int A[] = {0, 1, 2, 0, 1, 2} ;
    //sortColors(A, 6);
    //printv(A, 6);

    partition(A, 6, 0);
    printv(A, 6);

    return 0;
}
