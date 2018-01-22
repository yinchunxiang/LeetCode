/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/05/01 03:05:26
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void reverse_visit(vector<int>& result, TreeNode* from, TreeNode* to) {
        vector<int> temp;
        while (true) {
            temp.push_back(from->val);
            if (from == to) break;
            from = from->right;
        }
        result.push_back(temp.rbegin(), temp.rend());
    }
    vector<int> postorderTraversal(TreeNode* root) {
        /// write your code here
        vector<int> result;
        if (nullptr == root) return result;
        //TreeNode* pre = nullptr;
        TreeNode dummy(-1);
        dummy.left = root;
        root = &dummy;
        while (root) {
            if (nullptr == root->left) {
                //pre = root;
                root = root->right;
                continue;
            }
            TreeNode* node = root->left;
            while (nullptr != node->right && root != node->right) {
                node = node->right;
            }
            if (nullptr == node->right) {
                node->right = root;
                root = root->left;
            } else {
                reverse_visit(result, root->left, node);
                node->right = nullptr;
                root = root->right;
            }
        }
        return result;
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
