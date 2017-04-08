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
            TreeLinkNode* head = nullptr;
            TreeLinkNode* prev = nullptr;
            while (curr) {

            while (curr) {
                //left child
                if (curr->left) {
                    if (prev) {
                        prev->next = curr->left;
                    } else {
                        head = curr->left;
                    }
                    prev = curr->left;
                } 

                //right child
                if (curr->right) {
                    if (prev) {
                        prev->next = curr->right;
                    } else {
                        head = curr->right;
                    }
                    prev = curr->right;
                }
                curr = curr->next;
            }
            curr = head;
            head = nullptr;
            prev = nullptr;
            }
                    
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
