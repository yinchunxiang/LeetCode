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
 
struct Node {
    Node(int data): _data(data){
    }
    int data_;
    Node *left_ = NULL;
    Node *right_ = NULL;
}

void LeftView(Node* root) {

}


int main(int argc, char** argv) {
    Node *root = new Node(12);
    root->left_ = new Node(10);
    root->right_ = new Node(30);
    root->right_->left_ = new Node(25);
    root->right_->right = new Node(40);
}









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
