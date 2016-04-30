#include <iostream>

using namespace std;

int firstMissingPositive(int a[], int n) {
    for (int i = 0; i < n; i++) {
        while (a[i] != i+1) {
            if (a[i] <= 0 || a[i] > n) {
                break;
            }
            int temp = a[a[i] - 1];
            if (temp == a[i]) {
                break;
            }
            a[a[i] - 1] = a[i];
            a[i] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}


int main(int argc, const char *argv[])
{
    int a[] = {1,2,0};    
    cout << firstMissingPositive(a, 3) << endl;

    int b[] = {3,4,-1,1};
    cout << firstMissingPositive(b, 4) << endl;

    int c[] = {1,1};
    cout << firstMissingPositive(c, 2) << endl;

    int d[] = {2,2};
    cout << firstMissingPositive(d, 2) << endl;
    return 0;
}
