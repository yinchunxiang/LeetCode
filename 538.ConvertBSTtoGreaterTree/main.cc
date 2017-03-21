/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/19 11:18:14
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        void help(TreeNode* root, int &rs) {
            if (nullptr == root) {
                return;
            }
            help(root->right, rs);
            root->val += rs;
            rs += root->val;
            help(root->left, rs);
            return;
        }
        TreeNode* convertBST(TreeNode* root) {
            int rsum = 0;
            help(root, rsum);
            return root;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
