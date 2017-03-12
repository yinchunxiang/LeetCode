/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 23:36:58
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        /// write your code here
        if (nullptr == root) {
            return 0;
        }
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            } else {
                sum += sumOfLeftLeaves(root->left);
            }
        }
        if (root->right) {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
private:
    int sum_ = 0;
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
