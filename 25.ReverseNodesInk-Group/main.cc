//
// Created by yinchunxiang on 2018/9/3.
//

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* pre_group_tail = &dummy;
    ListNode* fast = head;
    while (fast) {
      int i = 0;
      for (; i < k; ++i) {
        if (!fast) break;
        fast = fast ->next;
      }
      if (i < k) break;
      ListNode* pre = head;
      ListNode* cur = head->next;
      while (cur != fast) {
        ListNode* temp = cur;
        pre->next = cur->next;
        cur = cur->next;
        temp->next = pre_group_tail->next;
        pre_group_tail->next = temp;
      }
      pre_group_tail = pre;
      head = fast;
    }
    return dummy.next;

  }
};
