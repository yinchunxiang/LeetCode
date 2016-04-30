/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/04/30 15:30:54
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        /// write your code here
        vector<int> result;
        if (nullptr == root) return result;
        while (root) {
            result.push_back(root->val);
            if (nullptr == root->left) {
                root = root->right;
                continue;
            }
            TreeNode* node = root->left;
            while (node && root != node->right) {
                node = node->right;
            }
            if (root == node->right) {
                node->right = nullptr;
                root = root->right;
            } else {
                node->right = root;
                root = root->left;
            }
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
