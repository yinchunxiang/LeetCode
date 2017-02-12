/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 21:50:01
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

typedef vector<int>::iterator It;
class Solution {
public:
    TreeNode* build(It b1, It e1, It b2, It e2) {
        if (b1 == e1 || b2 == e2) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(*b1);
        auto mid = find(b2, e2, *b1);
        auto left_size = distance(b2, mid);
        node->left = build(std::next(b1), b1 + left_size + 1, b2, mid);
        node->right = build(b1 + left + 1, e1, mid + 1, e2);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
