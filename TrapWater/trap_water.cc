#include <iostream>

using namespace std;


int trap(int A[], int n) {
    if (n <= 1) {
        return 0;
    }

    int result = 0;
    
    int start = 0;
    int end = 0;
    for (int i = 1; i < n; i++) {
        while (A[i] >= A[i - 1] && i < n) {
            start = i;
            ++i;
        }

        if (i >= n) {
            return 0;
        }

        while(A[i] <= A[i - 1] && i < n) {
            ++i;
        }
        if (i >= n) {
            return 0;
        }

        end = i;
        while (A[i] >= A[i - 1] && i < n) {
            end = i;
            ++i;
        }

        int upper = min(A[start], A[end]);
        while (start + 1 <= end - 1) {
            result = result + upper - A[start + 1];
            ++ start;
        }

        start = i - 1;

    }
    
    return result;
}

int main(int argc, const char *argv[])
{
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(a, 12) << endl;
    return 0;
}
