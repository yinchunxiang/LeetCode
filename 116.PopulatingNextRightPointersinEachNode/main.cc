/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 19:45:52
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        void connect(TreeLinkNode *root) {
            if (nullptr == root) return;
            queue<TreeLinkNode*> curr_level;
            queue<TreeLinkNode*> next_level;
            curr_level.push(root);
            while (!curr_level.empty()) {

                while (!curr_level.empty()) {
                    auto node = curr_level.front();
                    curr_level.pop();
                    if (!curr_level.empty()) {
                        node->next = curr_level.front();
                    }
                    if (node->left) {
                        next_level.push(node->left);
                    }
                    if (node->right) {
                        next_level.push(node->right);
                    }
                }
                curr_level.swap(next_level);
            }
            return;

        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
