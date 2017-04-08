/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 21:13:00
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            if (nullptr == head) {
                return nullptr;
            }
            if (nullptr == head->next) {
                return new TreeNode(head->val);
            }
            ListNode* prev = nullptr;
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next;
                if (fast->next) {
                    fast = fast->next;
                }
            }
            TreeNode* root = new TreeNode(slow->val);
            ListNode* lc = head;
            ListNode* rc = slow->next;
            prev->next = nullptr;
            slow->next = nullptr;
            root->left = sortedListToBST(lc);
            root->right = sortedListToBST(rc);
            return root;
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
