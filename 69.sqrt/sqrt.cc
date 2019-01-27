#include <iostream>

using namespace std;

int sqrt(int x) {
    if (x <= 1) {return x;}

    int low = 1; 
    int high = x/2;
    while (low <= high) {
        int mid = low + (high - low >> 1);
        int near = x/mid;//!!! prevent overflow
        if (mid == near) {
            return mid;
        }

        if (mid < near) {
            low = mid + 1;
        }
        else {
            high =  mid - 1;
        }
    }
    return high;
}

int main(int argc, const char *argv[])
{
    cout << sqrt(10) << endl; 
    cout << sqrt(2147395599) << endl; 
    return 0;
}


