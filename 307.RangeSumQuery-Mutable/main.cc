/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/21 22:26:20
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;
 
class NumArray {
public:
    NumArray(vector<int> nums) {
        int N = nums.size();
        size_ = N;
        vector<int> sum(2 * N, 0);
        sum.insert(sum.begin() + N, nums.begin(), nums.end());
        for (int i = N - 1; i > 0; --i) {
            sum[i] = sum[i<<1] + sum[i<<1|1];
        }
        sum_.swap(sum);
    }
    
    void update(int i, int val) {
        int index = size_ + i;
        sum_[index] = val;
        for (int j = index/2 ; j > 0; j /= 2) {
            sum_[j] = sum_[j << 1] + sum_[j << 1 | 1];
        }
    }
    
    // range[i, j]
    int sumRange(int i, int j) {
        int result = 0;
        int l = i + size_;
        int r = j + size_;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l == r) {
                cout << "left == right  +" << sum_[l] << endl;;
                result += sum_[l];
                break;

            }
            // left is odd
            if (l&1) {
                cout << "left is odd  +" << sum_[l] << endl;
                result += sum_[l++];
            } 
            // right is even
            if (!(r&1)) {
                cout << "right is even  +" << sum_[r] << endl;
                result += sum_[r--];
            }
        }
        return result;
        
    }

    void print() {
        cout << "{ ";
        for (auto i : sum_) {
            cout << i << " ";
        }
        cout << "}" << endl;
    }
private:
    vector<int> sum_;
    int size_;

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[]) {
    {
        vector<int> input = {1, 3, 5};
        cout << "input => ";
        printv(input);
        auto obj = new NumArray(input);
        obj->update(0, 2);
        obj->print();
        cout << obj->sumRange(0, 2) << endl;
    }
    cout << "=============================" << endl;
    return 0;
}











/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
