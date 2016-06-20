/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/06/19 23:23:46
 * @brief 
 * 
 **/ 
 
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        /// write your code here
        stack<const TreeNode*> s;
        auto p = root;
        int count = 0;
        while (!s.empty() || nullptr != p) {
            if (nullptr != p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                count += 1;
                if (k == count) {
                    return p->val;
                }
                p = p->right;
            }
        }
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
