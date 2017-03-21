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
struct SegmentTreeNode {
    int start_;
    int end_;
    int sum_ = 0;
    SegmentTreeNode(int start, int end) : start_(start), end_(end) {
    }
    SegmentTreeNode* left = nullptr;
    SegmentTreeNode* right = nullptr;
};

SegmentTreeNode* build(vector<int>& v, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    auto root = new SegmentTreeNode(start, end);
    if (start == end) {
        root->sum_ = v[start];
        return root;
    }
    int mid = start + (end - start)/2;
    root->left = build(v, start, mid);
    root->right = build(v, mid + 1, end);
    root->sum_ += root->left == nullptr ? 0 : root->left->sum_;
    root->sum_ += root->right == nullptr ? 0 : root->right->sum_;
    return root;
}

// 返回修改节点root得到的diff
int modify(int i, int val, SegmentTreeNode* root) {
    if (nullptr == root) {
        return val;
    }
    if (root->start_ == i && root->end_ == i) {
        int diff = val - root->sum_;
        root->sum_ = val;
        return diff;
    }
    auto mid = root->start_ + (root->end_ - root->start_)/2;
    auto diff = 0;
    if (i > mid) {
        diff = modify(i, val, root->right);
    } else {
        diff = modify(i, val, root->left);
    }
    root->sum_ += diff;
    return diff;
}

void traverse(SegmentTreeNode* root) {
    if (nullptr == root) {
        return;
    }
    cout << root->sum_ << " " << endl;
    traverse(root->left);
    traverse(root->right);
}

int query(int start, int end, SegmentTreeNode* root) {
    if (nullptr == root) {
        return 0;
    }
    if (start > end) {
        return 0;
    }
    if(start == root->start_ && end == root->end_) {
        return root->sum_;
    }
    int mid = root->start_ + (root->end_ - root->start_)/2;
    return query(start, min(end, mid), root->left) + query(max(start, mid + 1), end, root->right);
}


    public:
        NumArray(vector<int> nums) {
            int N = nums.size(); 
            root_ = build(nums, 0, N - 1);
        }

        void update(int i, int val) {
            modify(i, val, root_);

        }

        // range[i, j]
        int sumRange(int i, int j) {
            return query(i, j, root_);
        }

        void print() {
            traverse(root_);
        }
    private:
        SegmentTreeNode *root_ = nullptr;


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
