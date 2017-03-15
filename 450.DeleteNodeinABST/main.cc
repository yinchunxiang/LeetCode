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

    void d(TreeNode* curr, TreeNode* prev, int flag) {
        if (!curr->left && !curr->right) {
            if (-1 == flag) {
                prev->left = nullptr;
            }
            if (1 == flag) {
                prev->right = nullptr;
            }
            delete curr;
            return;
        }
        if (curr->left && !curr->right) {
            if (-1 == flag) {
                prev->left = curr->left;
            }
            if (1 == flag) {
                prev->right = curr->left;
            }
            delete curr;
            return ;
        }
        if (!curr->left && curr->right) {
            if (-1 == flag) {
                prev->left = curr->right;
            }
            if (1 == flag) {
                prev->right = curr->right;
            }
            delete curr;
            return;
        }
        auto target = curr;
        prev = curr;
        curr = curr->left;
        flag = -1;
        while (curr->right) {
            prev = curr;
            curr = curr->right;
            flag = 1;
        }
        swap(target->val, curr->val);
        d(curr, prev, flag);
    }
    

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (nullptr == root) {
            return root;
        }
        TreeNode *pp = new TreeNode(0);
        pp->right = root;
        TreeNode *prev = pp;
        TreeNode *curr = root;
        int flag = 1;
        bool find = false;
        while (curr) {
            if (key == curr->val) {
                find = true;
                break;
            }
            prev = curr;
            if (key < curr->val) {
                curr = curr->left;
                flag = -1;
            } else {
                curr = curr->right;
                flag = 1;
            }
        }

        if (!find) {
            return root;
        }
        d(curr, prev, flag);
        return pp->right;
    }

};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.deleteNode(nullptr, 0) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
