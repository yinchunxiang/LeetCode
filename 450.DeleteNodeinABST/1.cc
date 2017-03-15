/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/15 23:30:54
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (nullptr == root) {
            return root;
        }
        if (key == root->val) {
            if (!root->left) {
                auto r = root->right;
                delete root;
                return r;
            } else {
                auto node = root->left;
                while (node->right) {
                    node = node->right;
                }
                swap(node->val, root->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }

};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.deleteNode(nullptr, 0) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
