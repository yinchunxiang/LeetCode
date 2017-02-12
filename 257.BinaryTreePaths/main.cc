/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 13:30:36
 * @brief 
 * 
 **/ 

#include <string>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 

class Solution {
    public:
        void traverse(TreeNode* root, vector<string> &v, string path) {
            if (nullptr == root) {
                return;
            }
            path += std::to_string(root->val) + "->";

            if (nullptr == root->left && nullptr == root->right) {
                v.push_back(path.substr(0, path.size() - 2));
                return;
            }
            if (root->left) {
                traverse(root->left, v, path);
            }
            if (root->right) {
                traverse(root->right, v, path);
            }
        }

        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> v;
            traverse(root, v, "");
            return v;
        }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
