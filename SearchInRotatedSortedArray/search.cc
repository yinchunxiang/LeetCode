#include <iostream>

using namespace std;

bool search(int A[], int n, int target) {
    int low = 0;
    int hight = n - 1;
    while(low <= high) {
        int mid = low + (high - low >> 1);

        if (A[mid] == target) {
            return true;
        }

        if (A[low] < A[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return false;
}

int main(int argc, const char *argv[])
{

    return 0;
}


