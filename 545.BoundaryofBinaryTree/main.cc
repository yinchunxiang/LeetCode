/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/26 11:01:08
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void get_left_boundary(vector<int>& v, TreeNode* root) {
        while (root) {
            v.push_back(root->val);
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (v.size() > 1) {
            v.pop_back();
        }
        return;
    }
    void get_leaves(vector<int>& v, TreeNode* root) {
        if (nullptr == root) {
            return;
        }
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }
        get_leaves(v, root->left);
        get_leaves(v, root->right);
        return;
    }

    void get_right_boundary(vector<int>& v, TreeNode* root) {
        vector<int> t;
        while (root) {
            t.push_back(root->val);
            if (root->right) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        if (t.size() > 1) {
            v.insert(v.end(), next(t.rbegin()), t.rend());
        }
        
        return;
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        /// write your code here

        vector<int> result;
        if (nullptr == root) {
            return result;
        }
        result.push_back(root->val);
        if (!root->left && !root->right) {
            return result;
        }
        get_left_boundary(result, root->left);
        get_leaves(result, root);
        get_right_boundary(result, root->right);
        
        return result;
 
    }

};
int main(int argc, const char* argv[]) {
    Solution s;
    cout << s.boundaryOfBinaryTree(nullptr) << endl;
    return 0;
}
 












/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
