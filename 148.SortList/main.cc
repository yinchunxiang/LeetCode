class Solution {
    public:
        ListNode* merge(ListNode* list1, ListNode* list2) {
            if (nullptr == list1) return list2;
            if (nullptr == list2) return list1;
            if (list1->val < list2->val) {
                list1->next = merge(list1->next, list2);
                return list1;
            } else {
                list2->next = merge(list1, list2->next);
                return list2;
            }

        }

        ListNode* mergeSort(ListNode* head) {
            if (nullptr == head || nullptr == head->next) return head;
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* head2 = mergeSort(slow);
            prev->next = nullptr;
            ListNode* head1 = mergeSort(head);
            return merge(head1, head2);
        }



        ListNode* sortList(ListNode* head) {
            if (nullptr == head) return head;
            ListNode dummy(0);
            dummy.next = head;
            quicksort(&dummy, head, nullptr);
            return dummy.next;
        }
};
}
