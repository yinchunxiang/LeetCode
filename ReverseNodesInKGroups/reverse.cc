#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *reverseKGroup(ListNode *head, int k) {
    if (NULL == head) return head;
    if (k <= 1) return head;
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *nh = &dummy;

    ListNode *fast = head;
    ListNode *slow = fast;
    ListNode *nt = NULL;
    int steps = 0;
    while (1) {
        for (steps = 0; steps < k && NULL != fast; ++steps, fast = fast->next) {
        }
        if (steps < k) {
            break;
        }
        nt = slow;
        slow = slow->next;
        while (slow != fast) {
            ListNode* temp = slow;
            slow = slow->next;
            nt->next = temp->next;
            temp->next = nh->next;
            nh->next = temp;
        }
        nh = nt;
    }
    return dummy.next;
}

void print_list(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, const char *argv[])
{
    ListNode input_dummy(-1);
    ListNode *p = &input_dummy;
    for (int i = 2; i > 0; --i) {
        ListNode* temp = new ListNode(i);
        temp->next = p->next;
        p->next = temp;
    }
    print_list(p->next);
    ListNode* nh = reverseKGroup(p->next, 2);
    print_list(nh);


    return 0;
}
