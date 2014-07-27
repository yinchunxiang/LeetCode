#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

double FindKthOfTwoSortedArray(int A[], int m, int B[], int n, int k) {
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
    if ((m + n) % 2 == 0){
        int aplus = (left >= m) ? INT_MAX : A[left];
        int bplus = (k-left >= n) ? INT_MAX : B[k-left];
        int kth = max(ai, bj);
        return (double)(min(aplus, bplus) - kth)/2 + kth;
        //return (double)(min(aplus, bplus) + kth)/2;
    }
    else {
        return max(ai, bj);
    }
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m == 0 && n == 0) {
        return 0.0;
    }
    int k = (m + n - 1)/2 + 1;
    return FindKthOfTwoSortedArray(A, m, B, n, k);

}

int main(int argc, const char *argv[])
{
    int A[] = {1,2,3};
    int B[] = {1,2,3,4,5,6,7};
    cout << findMedianSortedArrays(A, 3, B, 7) << endl;
    cout << findMedianSortedArrays(A, 1, B, 7) << endl;
    cout << findMedianSortedArrays(A, 0, B, 1) << endl;
    cout << findMedianSortedArrays(A, 0, B + 1, 2) << endl;
    return 0;
}
