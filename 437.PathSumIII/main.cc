/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 14:36:57
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
    /// 要求传入的root必须不为空
    int countPathSum(TreeNode* root, int sum) {
        int count = sum == root->val ? 1 : 0;
        if (!root->left && !root->right) {
            return count;
        }
        int lc = 0;
        int rc = 0;
        if (root->left) {
            lc = countPathSum(root->left, sum - root->val);
        }
        if (root->right) {
            rc = countPathSum(root->right, sum - root->val);
        }
        
        return count + lc + rc;
    }
    int pathSum(TreeNode* root, int sum) {
        if (nullptr == root) {
            return 0;
        }
        int ret = 0;
        queue<TreeNode*> v;
        v.push(root);
        while (!v.empty()) {
            TreeNode* node = v.front();
            if (node->left) {
                v.push(node->left);
            }
            if (node->right) {
                v.push(node->right);
            }
            ret += countPathSum(node, sum);
            v.pop();
        }
        return ret;
    }
    int pathSum(TreeNode* root, int sum) {
        if (nullptr == root) {
            return 0;
        }
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int sumUp(TreeNode* root, int pre, int sum) {
        if (nullptr == root) {
            return 0;
        }
        int cur = pre + root->val;
        return (cur == sum) + sumUp(root->left, cur, sum) + sumUp(root->right, cur, sum);
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
