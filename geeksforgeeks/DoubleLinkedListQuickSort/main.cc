/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/08 21:38:13
 * @brief 
 * 
 **/ 

#include <iostream>

using namespace std;

class List {
    public:
        struct Node {
            int data;
            Node* next;
            Node* prev;
        };

        List() {
            head_ = new Node{0, nullptr, nullptr};
        }

        ~List() {
            while (nullptr != head_->next) {
                Node* node = head_->next;
                head_->next = node->next;
                if (node->next) {
                    node->next->prev = node->prev;
                }
                delete node;
            }
            delete head_;
        }

        Node* head() {
            return head_->next;
        }

        Node* tail() {
            if (nullptr == head_->next) {
                return nullptr;
            }
            Node* node = head_->next;
            while (nullptr != node->next) {
                node = node->next;
            }
            return node;
        }


        void push_front(int data) {
            Node *node = new Node{data, nullptr, nullptr};
            node->next = head_->next;
            head_->next = node;
            if (nullptr != node->next) {
                node->next->prev = node;
            }
            node->prev = head_;
            size_ += 1;
        }


        void print() {
            Node* node = head_->next;
            while (nullptr != node) {
                cout << node->data << " ";
                node = node->next;
            }
            cout << endl;
        }

        int size() {
            return size_;
        }

    private:
        Node *head_ = nullptr;
        int size_ = 0;
};

List::Node* partition(List::Node* begin, List::Node* end) {
    int pivot = end->data;
    List::Node* pb = begin->prev;
    for (List::Node* n = begin; n != end; n = n->next) {
        if (n->data < pivot) {
            swap(pb->next->data, n->data);
            pb = pb->next;
        }
    }
    swap(pb->next->data, end->data);
    return pb->next;
}

void quick_sort(List::Node* begin, List::Node* end) {
    if (begin == end) {
        return;
    }
    List::Node* mid = partition(begin, end);
    cout << "mid => " << mid->data << endl;
    if (mid->prev != begin->prev) {
        quick_sort(begin, mid->prev);
    }
    if (mid->next != end->next) {
        quick_sort(mid->next, end);
    }
}

int main(int argc, char *argv[]) {
    List l;
    l.push_front(30);
    l.push_front(3);
    l.push_front(4);
    l.push_front(20);
    l.push_front(5);

    cout << "before => ";
    l.print();

    quick_sort(l.head(), l.tail());
    //List::Node* pre_mid = partition(l.head_, l.head_->next, l.tail());
    //cout << "pre_mid => " << pre_mid->data << endl;
    
    cout << "after => ";
    l.print();
    return 0;
}













    /* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
