/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file stack.cc
 * @author yinchunxiang(@com)
 * @date 2016/05/01 16:30:13
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        /// write your code here
        vector<int> result;
        if (nullptr == root) return result;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        do {
            ///1 --> 入栈部分
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            ///2 --> 弹栈部分
            pre = nullptr;  ///入栈到最后都是左子为空，所以pre也为nullptr
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                ///cur->right已经访问过，或者为空
                ///访问当前节点
                if (cur->right == pre) {
                    result.push_back(cur->val);
                    pre = cur;
                } else {
                    s.push(cur);
                    cur = cur->right;
                    break;
                }
            }
        } while (!s.empty());
        return result;
         
    }
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.postorderTraversal(v) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
