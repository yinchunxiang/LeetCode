/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 2.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/06 22:36:26
 * @brief 
 * 
 **/ 

{
TreeNode* prev = nullptr;
TreeNode* first = nullptr;
TreeNode* second = nullptr;

void help(TreeNode* root) {
    if (nullptr == root) return;
    help(root->left);
    if (!first && prev && prev->val >= root->val) {
        first = prev;
    }
    if (first && prev && prev->val >= root->val) {
        second = root;
    }
    prev = root;
    help(root->right);
}
 
void recoverTree(TreeNode* root) {
    help(root);
    // 千万注意，只能互换值，不能互换指针
    swap(first->val, second->val);
}

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
