/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 22:14:34
 * @brief 
 * 
 **/ 

class Solution {
    public:
        bool valid(TreeNode* root, TreeNode* &last) {
            if (nullptr == root) return true;
            if (!valid(root->left, last)) {
                return false;
            }
            if (last && last->val >= node->val) {
                return false;
            }
            last = root;
            return valid(root->right, last);
            
        }
        bool isValidBST(TreeNode* root) {
            TreeNode* last = nullptr;
            return valid(root, last);
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
