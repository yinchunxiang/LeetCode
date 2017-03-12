/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 22:19:20
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void help(TreeNode* root) {
        if (nullptr == root) {
            return ;
        }
        help(root->left);
        if (nullptr == root->left) {
            prev_val = root->val;
            cur_ = 1;
            max_ = 1;
            v_.push_back(root->val);
        } else {
            if (root->val != prev_val) {
                prev_val = root->val;
                cur_ = 1;
            } else {
                ++cur_;
            }
            if (cur_ == max_) {
                v_.push_back(root->val);
            }
            if (cur_ > max_) {
                max_ = cur;
                v_.clear();
                v_.push_back(root->val);
            }
        }
        help(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        help(root);
        return v_;
    }
private:
    int prev_val;
    int cur_ = 0;
    int max_ = 0;
    vector<int> v_;
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
