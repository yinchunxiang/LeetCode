/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 23:46:30
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int count(TreeNode* root, int sum) {
        if (nullptr == root) {
            return 0;
        }
        int rest = sum - root->val;
        return (root->val == sum) + count(root->left, rest) + count(root->right, rest);
    }
    int pathSum(TreeNode* root, int sum) {
        /// write your code here
        if (nullptr == root) {
            return 0;
        }
        return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
