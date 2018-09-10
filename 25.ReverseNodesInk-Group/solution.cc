//
// Created by yinchunxiang on 2018/9/6.
//

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    ListNode* prev_group_tail = &dummy;
    ListNode* cur = dummy->next;
    int i = 0;
    while (head) {
      ListNode* temp = head;
      head = head->next;
      if (i == )

      temp->next = prev_group_tail->next;
      prev_group_tail->next = temp;


    }
    return dummy.next;
  }
}
