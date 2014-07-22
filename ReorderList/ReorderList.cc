#include <iostream>
#include <list> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head) {
    if (NULL == head) {
        return head;
    }
    if (NULL == head->next) {
        return head;
    }
    ListNode* ret = NULL;
    while(head) {
        ListNode* temp = head;
        head = head->next;
        temp->next = ret;
        ret = temp;
    }
    return ret;
}
void reorderList(ListNode *head) {
    if(NULL == head) {
        return ;
    }
    if(NULL == head->next) {
        return;
    }
    ListNode* preslow = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) {
        preslow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    preslow->next = NULL;

    slow = reverse(slow);
    ListNode* ts = slow;
    while(ts) {
        cout << ts->val << endl;
        ts = ts->next;
    }

    ListNode* p = head;
    ListNode dummy(-1);
    ListNode* cur = &dummy;
    while(p && slow) {
        cur->next = p;
        cur = cur->next;
        p = p->next;
        cur->next = slow;
        cur = cur->next;
        slow = slow->next;
    }

    if (p) {
        cur->next = p;
    }
    else {
        cur->next = slow;
    }

    head = dummy.next;
}

int main(int argc, const char *argv[])
{
    ListNode dummy(-1);
    ListNode* p = &dummy;
    for (int i = 0; i < 3; ++i) {
        ListNode* ln = new ListNode(i+1);
        p->next = ln;
        p = p->next;
    }

    reorderList(dummy.next);
    p = dummy.next;
    while(p) {
        cout << p->val << endl;
        p = p->next;
    }


    return 0;
}
