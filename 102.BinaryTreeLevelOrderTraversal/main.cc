/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 18:03:40
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (nullptr == root) {
            return v;
        }
 		queue<TreeNode*> q;
        q.push(root);
        int n = 1;
        while (!q.empty()) {
            vector<int> vi(n, 0);
            for (int i = 0; i < n; ++i) {
                auto node = q.front();
                vi[i] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
            }
            v.push_back(vi);
            n = q.size();
        }
        return v;
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
