/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/15 22:19:07
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void help(TreeNode* root, int level, vector<int>& v) {
        if (nullptr == root) {
            return;
        }
        if (v.size() > level) {
            v[level] = max(v[level], root->val);
        } else {
            v.push_back(root->val);
        }
        help(root->left, level + 1, v);
        help(root->right, level + 1, v);
    }
    vector<int> largestValues(TreeNode* root) {
        /// write your code here
        vector<int> result;
        help(root, 0, result);
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
