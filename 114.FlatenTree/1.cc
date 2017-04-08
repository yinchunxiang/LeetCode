/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 20:47:46
 * @brief 
 * 
 **/ 
 
void flatten(TreeNode* root) {
    if (nullptr == root) return ;
    TreeNode* lc = root->left;
    TreeNode* rc = root->right;
    root->left = nullptr;
    flatten(lc);
    flatten(rc);
    root->right = lc;
    TreeNode* node = root;
    while (node->right) {
        node = node->right;
    }
    node->right = rc;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
