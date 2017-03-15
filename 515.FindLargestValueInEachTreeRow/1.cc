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
    vector<int> larger(vector<int> &l, vector<int> &r) {
        int M = l.size();
        int N = r.size();
        vector<int> result(max(M, N), 0);
        int i = 0; 
        int j = 0;
        for (;i < M && j < N; ++i, ++j) {
            result[i] = max(l[i], r[i]);
        }
        if (i < M) {
            for (; i < M; ++i) {
                result[i] = l[i];
            }
        }
        if (j < N) {
            for (; j < N; ++j) {
                result[j] = r[j];
            }
        }
        return result;
    }
    vector<int> largestValues(TreeNode* root) {
        /// write your code here
        vector<int> result;
        if (nullptr == root) {
            return result;
        }
        auto l = largestValues(root->left);
        auto r = largestValues(root->right);
        auto s = larger(l, r);
        result.push_back(root->val);
        result.insert(result.end(), s.begin(), s.end());
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
