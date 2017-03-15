/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/15 21:59:15
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (nullptr == root) {
            return root;
        }
        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
