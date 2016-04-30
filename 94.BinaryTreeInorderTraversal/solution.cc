/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/05/01 01:35:57
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (nullptr == root) return result;
        while(root) {
            if (nullptr == root->left) {
                result.push_back(root->val);
                root = root->right;
                continue;
            }
            TreeNode* node = root->left;
            while (nullptr != node->right && root != node->right) {
                node = node->right;
            }
            if (nullptr == node->right) {
                node->right = root;
                root = root->left;
            } else {
                node->right = nullptr;
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
            
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
