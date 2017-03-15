/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/15 22:40:20
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        void help(TreeNode* root, int level, int &max_level, int &left_most) {
            if (nullptr == root) {
                return;
            }
            if (++level > max_level) {
                max_level = level;
                left_most = root->val;
            }
            help(root->left, level, max_level, left_most);
            help(root->right, level, max_level, left_most);
        }

        int findBottomLeftValue(TreeNode* root) {
            /// write your code here
            int max_level = 0;
            int left_most = root->val
            help(root, 0, max_level, left_most);
            return left_most;
        }

};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
