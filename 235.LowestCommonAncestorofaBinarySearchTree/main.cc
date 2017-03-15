/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/13 21:15:42
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while (nullptr != root) {
                if (root->val > p->val && root->val > q->val) {
                    root = root->left;
                    continue;
                }
                if (root->val < p->val && root->val < q->val) {
                    root = root->right;
                    continue;
                }
                return root;
            }
            return root;
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
