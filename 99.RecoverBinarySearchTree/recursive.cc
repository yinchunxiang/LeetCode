/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file recursive.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/13 23:46:41
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        // inorder traversal
        TreeNode *first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;
        void recover(TreeNode* root) {
            if (nullptr == root) {
                return;
            }
            recover(root->left);
            if (nullptr == first) {
                if (prev && prev->val > root->val) {
                    first = prev;
                }
            } 
            ///这2个if一定要分开
            if (nullptr != first){
                if (prev && prev->val > root->val) {
                    second = root;
                }
            }
            prev = root;
            if (root->right) {
                recover(root->right, prev);
            }
        }
        void recoverTree(TreeNode* root) {
            recover(root);
            if (first && second) {
                swap(first->val, second->val);
            }
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
