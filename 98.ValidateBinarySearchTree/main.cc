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
        bool isValidBST(TreeNode* root) {
            if (nullptr == root) return true;
            if (!isValidBST(root->left)) return false;
            if (!isValidBST(root->right)) return false;
            if (root->left) {
                auto node = root->left;
                while (node->right) {
                    node = node->right;

                }
                if (node->val >= root->val) return false;

            }
            if (root->right) {
                auto node = root->right;
                while (node->left) {
                    node = node->left;

                }
                if (node->val <= root->val) return false;

            }
            return true;


        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
