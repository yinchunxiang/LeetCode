/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 20:18:16
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        void connect(TreeLinkNode *root) {
            TreeLinkNode* curr = root;
            while (root) {
                TreeLinkNode next_level_head(0);
                TreeLinkNode* node = &next_level_head;
                while (root) {

                    if (root->left) {
                        node->next = root->left;
                        node = node->next;
                    }
                    if (root->right) {
                        node->next = root->right;
                        node = node->next;
                    }
                    root = root->next;
                }
                root = next_level_head->next;

            }


        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
