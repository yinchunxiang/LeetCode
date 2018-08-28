//
// Created by yinchunxiang on 2018/8/28.
//

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:

  void insert(ListNode* prev, ListNode* temp) {
    while (prev->next && prev->next->val < temp->val) {
      prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
    return;
  }

//  void insert(ListNode dummy, ListNode* temp) {
//    ListNode* prev = &dummy;
//    ListNode* cur = dummy.next;
//    while (cur) {
//      if (temp->val < cur->val) {
//        temp->next = cur;
//        prev->next = temp;
//        break;
//      }
//      prev = cur;
//      cur = cur->next;
//    }
//    if (nullptr == cur) {
//      temp->next = cur;
//      prev->next = temp;
//    }
//    return;
//  }

  ListNode* insertionSortList(ListNode* head) {
    if (nullptr == head || nullptr == head->next) return head;
    ListNode dummy(0);
    dummy.next = nullptr;

    while (head) {
      ListNode* temp = head;
      head = head->next;
      insert(&dummy, temp);
    }

    return dummy.next;
  }
};

