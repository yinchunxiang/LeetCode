/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/13 21:03:56
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void help(TreeNode* root, string path) {
        if (nullptr == root) {
            return;
        }
        path += std::to_string(root->val);
        if (!root->left && !root->right) {
            v_.push_back(path);
            return;
        }
        path += "->"
        help(root->left, path);
        help(root->right, path);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        help(root, path);
        return v_;
         
    }
private:
    vector<string> v_;
};

int main(int argc, const char* argv[]) {
    vector<int> v = {};
    Solution s;
    cout << s.solve(v) << endl;
    return 0;
}
 













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
