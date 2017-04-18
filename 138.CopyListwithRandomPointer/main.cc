/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/09 22:49:41
 * @brief 
 * 
 **/ 
 
RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return nullptr;
    RandomListNode* l1 = nullptr;
    RandomListNode* l2 = nullptr;
    for (l1 = head; l1; l1 = l1->next->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
    }
    for (l1 = head; l1; l1 = l1->next->next) {
        l2 = l1->next;
        if (l1->random) {
            l2->random = l1->random->next;
        }
    }
    auto new_head = head->next;
    for (l1 = head; l1; l1 = l1->next) {
        l2 = l1->next;
        l1->next = l2->next;
        if (l2->next) {
            l2->next = l2->next->next;
        }
    }
    return new_head;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
