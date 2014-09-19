ListNode *deleteDuplicates(ListNode *head) {
    if (NULL == head) { return head; }

    ListNode dummy(head->val - 1);
    dummy.next = head;
    ListNode* slow_prev = NULL;
    ListNode* slow = &dummy;
    ListNode* fast = slow->next;
    while (fast) {
        if (slow->val != fast->val) {
            if (slow->next == fast) {
                slow_prev = slow;
                slow = slow->next;
                fast = fast->next;
            }
            else {
                while(slow_prev->next != fast) {
                    ListNode* todel = slow;
                    slow_prev->next = slow->next;
                    slow = slow->next;
                    delete todel;
                }
            }
        }
        else {
            fast = fast->next;
        }
    }
    if (slow->next != fast) {
        while(slow_prev->next != fast) {
            ListNode* todel = slow;
            slow_prev->next = slow->next;
            slow = slow->next;
            delete todel;
        }
    }
    return dummy.next;
}
