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

        Node* begin() {
            return head_->next;
        }

        Node* end() {
            return nullptr;
        }

        Node* mid() {
            Node* fast = head_->next;
            Node* slow = head_->next;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        }

        Node* midsplit() {
            auto fast = head_->next;
            auto slow = head_->next;
            while (fast && fast->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            auto temp = slow->next;
            temp->prev = nullptr;
            slow->next = nullptr;
            return temp;
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

List::Node *med(List::Node *begin, List::Node *end) {
    auto fast = begin;
    auto slow = begin;
    while (fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}



string get_level(int level) {
    string ret = "";
    for (int i = 0; i < level; ++i) {
        ret += "    | ";
    }
    return ret;
}

// 返回合并之后的尾巴
List::Node *merge(List::Node *node, List::Node *b1, List::Node *e1, List::Node *b2, List::Node *e2, int level) {
    auto prev = node;

    /*
    auto p = node->next;
    auto q = e2->next;
    cout << get_level(level) << "beforemerge :";
    while (p != q) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    */


    while (b1 != e1->next && b2 != e2->next) {
        List::Node *temp = nullptr;
        if (b1->data < b2->data) {
            temp = b1;
            b1 = b1->next;
        } else {
            temp = b2;
            b2 = b2->next;
        }
        // 摘除temp
        temp->prev->next = temp->next;
        if (temp->next) {
            temp->next->prev = temp->prev;
        }

        // temp加入到prev后面
        temp->next = prev->next;
        prev->next = temp;
        temp->prev = prev;
        if (temp->next) {
            temp->next->prev = temp;
        }

        // prev 后移一位
        prev = temp;

        /*
        auto p = node->next;
       // cout << "q => " << q << endl;
        cout << get_level(level) << "afteremerge :";
        while (p != q) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
        */
    }
    if (b1 != e1->next) {
        return e1;
    }
    if (b2 != e2->next) {
        return e2;
    }
}


// [begin, end] 是个前闭后闭的区间
List::Node *merge_sort(List::Node *begin, List::Node *end, int level) {
    if (nullptr == begin || begin == end) {
        return begin;
    }
    cout << get_level(level) << "input => ";
    for (auto p = begin; p != end->next; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
    auto mid = med(begin, end);
    cout << get_level(level) << "mid => " << mid->data << endl;


    auto lprev = begin->prev;

    cout << get_level(level) << "before1 => " ;
    for (auto node = lprev->next; node != mid->next; node = node->next) {
        cout << node->data << " " ;
    }
    cout << endl;

    auto ltail = merge_sort(begin, mid, level + 1);

    cout << get_level(level) << "after1 => " ;
    for (auto node = lprev->next; node != ltail->next; node = node->next) {
        cout << node->data << " " ;
    }
    cout << endl;


    cout << get_level(level) << "before2 => ";
    for (auto node = ltail->next; node != end->next; node = node->next) {
        cout << node->data << " " ;
    }
    cout << endl;

    auto rtail = merge_sort(ltail->next, end, level + 1);

    cout << get_level(level) << "after2 => ";
    for (auto node = ltail->next; node != rtail->next; node = node->next) {
        cout << node->data << " " ;
    }
    cout << endl;

    auto tt =  merge(lprev, lprev->next, ltail, ltail->next, rtail, level);
    cout << get_level(level) << "tail => " << tt->data << endl;;
    return tt;
    
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

    auto mid = med(l.begin(), l.end());
    //cout << "mid => " << mid->data << endl;
    cout << "head => " << l.head()->data << endl;
    cout << "tail => " << l.tail()->data << endl;
    cout << "prev => " << l.head()->prev->data << endl;

    //merge(l.head()->prev, l.head(), mid, mid->next, l.tail(), 0);

    int level = 0;
    merge_sort(l.head(), l.tail(), level);
    //List::Node* pre_mid = partition(l.head_, l.head_->next, l.tail());
    //cout << "pre_mid => " << pre_mid->data << endl;
    
    cout << "after => ";
    l.print();
    return 0;
}













    /* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
