/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/05 19:53:04
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

class MinHeap {
    public:
        MinHeap(vector<int>::iterator begin, vector<int>::iterator end): data_(begin, end) {
            //根据vector构建堆
            size_ = data_.size();
            int index = (size_ - 2)/2;
            while (index >= 0) {
                adjust(index--);
            }
        }
        bool empty() {
            return 0 >= size_;
        }
        void pop() {
            swap(data_[0], data_[size_ - 1]);
            size_ -= 1;
            if (size_ > 0) {
                adjust(0);
            }
        }

        int top() {
            return data_.front();
        }

        void ReplaceTop(int value) {
            if (data_.empty()) {
                data_.push_back(value);
                return;
            }
            data_[0] = value;
            adjust(0);
        }

        const vector<int>& data() {
            return data_;
        }

    private:
        int left(int i) {
            return 2 * i + 1;
        }

        int right(int i) {
            return 2 * i + 2;
        }

        void adjust(int i) {
            //cout << "adjust " << i << endl;
            int lc = left(i);
            if (lc >= size_) {
                return;
            }
            int rc = right(i);
            if (rc >= size_) {
                if (data_[i] <= data_[lc]) {
                    return;
                }
                swap(data_[i], data_[lc]);
                adjust(lc);
                return;
            }
            int t = lc;
            if (data_[lc] >  data_[rc]) {
                t = rc;
            }
            if (data_[i] <= data_[t]) {
                return;
            }
            swap(data_[i], data_[t]);
            adjust(t);
        }

        vector<int> data_;
        int size_;
};

void mysortk(vector<int> &v, int k) {
    auto it = v.begin();
    advance(it, k + 1);
    MinHeap min_heap(v.begin(), it);
    int n = v.size();
    vector<int> output;
    output.reserve(n);
    for (int i = k + 1; i < n; ++i) {
        output.push_back(min_heap.top());
        min_heap.ReplaceTop(v[i]);
    }
    while (!min_heap.empty()) {
        output.push_back(min_heap.top());
        min_heap.pop();
    }
    v.swap(output);
}

void sortk(vector<int> &v, int k) {
    /// 创建小顶堆
    auto it = v.begin();
    std::advance(it, k + 1);
    priority_queue<int, std::vector<int>, std::greater<int>> min_heap(v.begin(), it);
    vector<int> output;
    output.reserve(v.size());
    for (int i = k + 1; i < v.size(); ++i) {
        output.push_back(min_heap.top());
        min_heap.pop();
        min_heap.push(v[i]);
    }
    while(!min_heap.empty()) {
        output.push_back(min_heap.top());
        min_heap.pop();
    }
    v.swap(output);
}

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int k = 3;
    vector<int> v = {2, 6, 3, 12, 56, 8};

    
    cout << "=> before" << endl;
    printv(v);

    cout << "=> min_heap" << endl;
    MinHeap mh(v.begin(), v.end());
    while (!mh.empty()) {
        cout << mh.top() << " ";
        mh.pop();
    }
    cout << endl;


    mysortk(v, k);

    cout << "=> after" << endl;
    printv(v);


    return 0;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
