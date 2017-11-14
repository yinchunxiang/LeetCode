//
// Created by yinchunxiang on 14/11/2017.
//

#include <iostream>

using namespace std;

class Solution {
public:

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n ;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = getCount(mid, m, n);
            // 要保证是第k大，就是比他再小的就不能满足条件
            // 在k == count的时候不能返回，是因为mid值可能不在乘法表中，
            // 所以，需要压缩到极限，压缩到极限的时候，那个值肯定在乘法表中
            // 此时才可以返回, 因为此时包含了它自身
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high
    }

private:
    //在这个计数里面包含value自己了，因为value/i可能等于1
    //获取的是<=value的元素的个数
    int getCount(int mid, int m, int n) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(mid / i, n);
        }
        return count;
    }
};


int main(int argc, char *argv[]) {
    Solution s;
    cout << s.findKthNumber(2, 3, 6) << endl;
    cout << s.findKthNumber(45, 12, 471) << endl;
    return 0;
}
