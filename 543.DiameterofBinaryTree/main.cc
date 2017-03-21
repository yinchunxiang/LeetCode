/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/19 11:01:11
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int help(TreeNode* root, int &maxlen) {
            if (nullptr == root) {
                return 0;
            }
            auto lh = help(root->left);
            auto rh = help(root->right);
            auto h = 1 + max(lh, rh);
            auto len = lh + rh;
            maxlen = max(maxlen, len);
            return h;
        }


        int diameterOfBinaryTree(TreeNode* root) {
            if (nullptr == root) {
                return 0;
            }
            int maxlen = 0;
            help(root, maxlen);
            return maxlen;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
