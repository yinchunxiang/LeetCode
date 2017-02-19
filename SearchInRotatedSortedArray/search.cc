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

class Solution {
    public:
        bool search(vector<int> &A, int n, int target) {
            int first = 0, last = n;
            while (first != last) {
                const int mid = (first + last) / 2;
                if (A[mid] == target)
                    return true;
                if (A[first] < A[mid]) {
                    if (A[first] <= target && target < A[mid])
                        last = mid;
                    else
                        first = mid + 1;

                } else if (A[first] > A[mid]) {
                    if (A[mid] < target && target <= A[last-1])
                        first = mid + 1;
                    else
                        last = mid;

                } else {
                    //skip duplicate one
                    first++;
                }

            }
            return false;

        }
        bool search(vector<int>& nums, int target) {
            return search(nums, 0, nums.size(), target);

        }

};

int main(int argc, const char *argv[])
{

    return 0;
}


