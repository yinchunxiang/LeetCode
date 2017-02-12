/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 19:42:16
 * @brief 
 * 
 **/ 
 
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty()
    }

    /** @return the next smallest number */
    int next() {
        auto p = s.top();
        s.pop();
        if (p->right) {
            find_left(p->right);
        }
        return p->val;
    }
private:
    void find_left(TreeNode* root) {
        auto p = root;
        while (p) {
            s.push(p);
            p = p->next;
        }
    }
    stack<TreeNode*> s

};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
