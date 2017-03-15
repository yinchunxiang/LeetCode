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
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            auto temp = node->left;
            node->left = node->right;
            node->right = temp;
            if (node->left) {
                s.push(node->left);
            }
            if (node->right) {
                s.push(node->right);
            }
        }
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
