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
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                s.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
            
    }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
