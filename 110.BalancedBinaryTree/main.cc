/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 16:16:51
 * @brief 
 * 
 **/ 
 

class Solution {
    public:
        bool balanced(TreeNode* root, int &h) {
            if (nullptr == root) {
                h = 0;
                return true;
            }
            int lh = 0;
            bool lb  = balanced(root->left, lh);
            int rh = 0;
            bool rb = balanced(root->right, rh);
            h = 1 + max(lh, rh);
            if (!lb || !rb) {
                return false
            }
            if (1 < abs(lh - rh)) {
                return false;
            }
            return true;
        }

        bool isBalanced(TreeNode* root) {
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
