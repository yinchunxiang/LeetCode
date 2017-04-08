/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 19:58:06
 * @brief 
 * 
 **/ 
 
void connect(TreeLinkNode *root) {
    TreeLinkNode* curr = nullptr;
    TreeLinkNode* next = root;
    while (next->left) {
        curr = next;
        while (curr) {
            curr->left->next = curr->right;
            if (curr->next) {
                curr->right->next = cur->next->left;
            }
            curr = curr->next;
        }
        next = next->left;
    }
    return;

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
