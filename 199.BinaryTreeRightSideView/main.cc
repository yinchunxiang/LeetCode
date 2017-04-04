/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/31 20:59:16
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void help(TreeNode* root, vector<int>& v, int level) {
        if (nullptr == root) {
            return;
        }
        if (level >= v.size()) {
            v.push_back(root->val);
        }
        help(root->right, v, level + 1);
        help(root->left, v, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 0;
        help(root, result, 0);
        return result;
    }

};

int main(int argc, const char* argv[]) {
    Solution s;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
