/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2016/12/06 20:59:07
 * @brief 
 * 
 **/ 

#include <list>
 
struct Node {
    Node(int data): data_(data){
    }
    int data_;
    Node *left_ = nullptr;
    Node *right_ = nullptr;
};

void LeftView(Node* root) {
    if (NULL == root) {
        return;
    }
    std::list<Node*> cur_level;
    std::list<Node*> next_level;
    cur_level.push_back(root);
    while (!cur_level.empty()) {
        printf("%d\n", cur_level.front()->data_);
        for(auto&& node : cur_level) {
            if (node->left_) {
                next_level.push_back(node->left_);
            }
            if (node->right_) {
                next_level.push_back(node->right_);
            }
        }
        cur_level.clear();
        cur_level.swap(next_level);
    }
}


int main(int argc, char** argv) {
    Node *root = new Node(12);
    root->left_ = new Node(10);
    root->right_ = new Node(30);
    root->right_->left_ = new Node(25);
    root->right_->right_ = new Node(40);
    LeftView(root);
}









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
