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
        // 不影响原来链表的方法
        TreeNode* sb(ListNode* head, ListNode* tail) {
            if (tail == head) {
                return nullptr;
            }
            if (tail == head->next) {
                return new TreeNode(head->val);
            }
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast != tail && fast->next != tail) {
                slow = slow->next;
                fast = fast->next->next;
            }
            TreeNode* root = new TreeNode(slow->val);
            root->left = ss(head, slow);
            root->right = ss(slow, tail);
            return root;
        }
        TreeNode* sortedListToBST(ListNode* head) {
            return ss(head, nullptr);
                
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
