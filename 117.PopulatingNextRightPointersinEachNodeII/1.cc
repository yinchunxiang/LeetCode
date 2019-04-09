/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 20:18:16
 * @brief 
 * 
 **/
class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() {}

  Node(int _val, Node* _left, Node* _right, Node* _next) {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};

class Solution {
public:
  void connect(Node* root, Node* next_level_prev) {
    if (nullptr == root) return ;
    if (next_level_prev)  next_level_prev->next = root->left;
    Node* nn = nullptr;
    if (root->left) {
      // 先处理当前的
      root->left->next = root->right;
      if (next_level_prev) {
        nn = next_level_prev->right ? next_level_prev->right : next_level_prev->left;
      }
      connect(root->left, nn);
      if (root->left->left) {
        if (nn) nn->next = root->left->left;
        nn = root->left->left;
      }
      if (root->left->right) {
        if (nn) nn->next = root->left->right;
        nn = root->left->right;
      }
    }
    if (root->right) {
      connect(root->right, nn);
    }


  }
  void connect(Node *root) {
    connect(root, nullptr);
  }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
