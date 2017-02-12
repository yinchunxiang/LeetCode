/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 16:07:03
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
        TreeNode* invertTree(TreeNode* root) {
            if (nullptr == root) {
                return root;
            }
            /// 这样写不对，影响下面的操作了
            //root->left = invertTree(root->right);
            //root->right = invertTree(root->left);
            invertTree(root->right);
            invertTree(root->left);
            swap(root->left, root->right);
            return root;
        }

        TreeNode* invertTree(TreeNode* root) {
            if (nullptr == root) {
                return root;
            }
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()) {
                auto node = q.front();
                swap(node->left, node->right);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
            }
            return root;
        }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
