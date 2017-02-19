/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/02/12 23:29:08
 * @brief 
 * 
 **/ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<TreeNode*> generate(int begin, int end) {
            vector<TreeNode*> v;
            if (begin > end) {
                v.push_back(nullptr);
                return v;
            }
            for (int i = begin; i <= end; ++i) {
                auto lv = generate(begin, i - 1);
                auto rv = generate(i + 1, end);
                for (auto l : lv) {
                    for (auto r : rv) {
                        auto node = new TreeNode(i);
                        node->left = l;
                        node->right = r;
                        v.push_back(node);
                    }
                }
            }
            return v;
        }

        vector<TreeNode*> generateTrees(int n) {
            return generate(1, n);
        }
};

int main(int argc, char *argv[])
{
    Solution s;
    cout << "n => " << 3 << endl;
    cout << s.numTrees(3) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
