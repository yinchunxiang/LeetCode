/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/05/01 01:53:02
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
    void recoverTree(TreeNode* root) {
        if (nullptr == root) return;
        TreeNode* pre = nullptr;
        TreeNode* n1 = nullptr;
        TreeNode* n2 = nullptr;
        bool flag = false;
        while (root) {
            if (nullptr == root->left) {
                if (pre && pre->val > root->val) {
                    if (!flag) {
                        n1 = pre;
                        flag = true;
                    }
                    n2 = root;
                }
                pre = root;
                root = root->right;
                continue;
            }
            TreeNode* node = root->left;
            while (nullptr != node->right && root != node->right) {
                node = node->right;
            }
            if (nullptr == node->right) {
                node->right = root;
                pre = node;
                root = root->left;
            } else {
                if (pre && pre->val > root->val) {
                    if (!flag) {
                        n1 = pre;
                        flag = true;
                    }
                    n2 = root;
                }
                node->right = nullptr;
                pre = root;
                root = root->right;
            }
        }
        if (n1 && n2) {
            swap(n1->val, n2->val);
        }
            
    }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
