/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/01/02 00:34:10
 * @brief 
 * 
 **/ 

#include <iostream>
#include <algorithm>

struct Node {
    Node* l = nullptr;
    Node* r = nullptr;
    int data_;
    Node(int data) : data_(data) {
    }
};

int diameter(Node* root, int &height) {
    if (nullptr == root) {
        height = 0;
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int ld = diameter(root->l, lh);
    int rd = diameter(root->r, rh);
    height = 1 + std::max(ld, rd);
    return std::max(1 + lh + rh, std::max(ld, rd));
}

int main(int argc, char *argv[]) {
    struct Node *root   = new Node(1);
    root->l             = new Node(2);
    root->r             = new Node(3);
    root->l->l          = new Node(4);
    root->l->r          = new Node(5);
    int h = 0;
    std::cout << diameter(root, h) << std::endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
