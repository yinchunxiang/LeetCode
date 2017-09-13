/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/13 11:22:34
 * @brief 
 * 
 **/ 
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (nullptr == root) {
            return result;
        }
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* node = s.top();
            if (nullptr == node->left && nullptr == node->right) {
                result.push_back(node->val);
                s.pop();
                continue;
            }
            if (node->right) {
                s.push(node->right);
                node->right = nullptr;
            }
            if (node->left) {
                s.push(node->left);
                node->left = nullptr;
            }
        }
        return result;
        
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
