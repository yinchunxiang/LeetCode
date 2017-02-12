/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 19:23:34
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
    int height(TreeNode* root) {
        int h = 0;
        while (root) {
            h += 1;
            root = root->left;
        }
    }
    int countNodes(TreeNode* root) {
        int count = 0;
 		if (nullptr == root) {
            return count;
		}

        int lh = height(root->left);
        int rh = height(root->right);

        if (lh == rh) {
            // 左子树是满二叉树
            count += (1 << lh) + countNodes(root->right);
        } else {
            // 右子树是满二叉树
            count += (1 << rh) + countNodes(root->left);
        }
        return count;
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
