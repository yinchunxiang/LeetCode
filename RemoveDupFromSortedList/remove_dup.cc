#include <iostream>

ListNode *deleteDuplicates(ListNode *head) {
    if (NULL == head) return head;
    ListNode dummy(head->val - 1);
    dummy.next = head;
    ListNode* slow = &dummy;
    ListNode* fast = head;
    while(fast) {
        if (slow->val != fast->val) {
            slow = slow->next;
            fast = fast->next;
        }
        else {
            fast = fast->next;
            while(slow->next != fast) {
                ListNode* todel = slow->next;
                slow->next = todel->next;
                delete todel;
            }
        }
    }
    return dummy.next;
}

