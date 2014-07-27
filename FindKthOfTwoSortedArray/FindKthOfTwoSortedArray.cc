#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;


int FindKthOfTwoSortedArray(int A[], int m, int B[], int n, int k) {
    if ( m > n) {
        return FindKthOfTwoSortedArray(B, n, A, m, k);
    }
    int left = 0; 
    int right = m - 1;
    while (left <= right) {
        int mid = left + (right-left >> 1);
        cout << "left " << left << " " ;
        cout << "right " << right << " ";
        cout << "mid " << mid << endl;
        int j = k - 1 - mid;
        if (j < 0) {
            right = mid - 1;
            continue;
        }

        if ( j >= n) {
            left = mid + 1;
            continue;
        }

        if (B[j] == A[mid]) {
            return B[j];
        }
        else if(A[mid] < B[j]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    int ai = (left - 1 < 0)? INT_MIN : A[left - 1];
    int bj = (k - left - 1 < 0) ? INT_MIN : B[k-1-left];
    return max(ai, bj);
}

int main(int argc, const char *argv[])
{
    int A[] = {1,2,3};
    int B[] = {1,2,3,4,5,6,7};
    cout << "k = 3 => " <<  FindKthOfTwoSortedArray(A, 3, B, 7, 3) << endl;
    cout << "k = 4 => " << FindKthOfTwoSortedArray(A, 3, B, 7, 4) << endl;

    return 0;
}
