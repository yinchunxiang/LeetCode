/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/06 22:15:48
 * @brief 
 * 
 **/ 


class Solution {
    public:
        int dfs(int& max_sum, TreeNode* root) {
            if (nullptr == root) {
                return 0;

            }
            int lh = max(0, dfs(max_sum, root->left));
            int rh = max(0, dfs(max_sum, root->right));
            max_sum = max(max_sum, lh + rh + root->val);
            return root->val + max(lh, rh);

        }
        int maxPathSum(TreeNode* root) {
            int max_sum = INT_MIN;
            dfs(max_sum, root);
            return max_sum;

        }
};












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
