//
// Created by alexkkk on 1/22/18.
//

#include <iostream>

using namespace std;


class Solution {
public:

    int getCount(int cur, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(m/i, n);
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        while (low < high) {
            int mid = low + (high - low)/2;
            int count = getCount(mid, m, n);
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high;
    }
};