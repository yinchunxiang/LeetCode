/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/12 11:59:29
 * @brief 
 * 
 **/ 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
 
class Solution {
    public:
        int left_tree_pos(string& str, int start) {
            stack<char> s;
            int N = str.size();
            for (int i = start; i < N; ++i) {
                if ('(' = str[i]) {
                    s.push(str[i]);
                } else if (')' == str[i]) {
                    s.pop();
                } else {
                }
                if (s.empty()) {
                    return i;
                }
            }
            return N;
        }
        TreeNode* str2tree(string s) {
            int N = s.size();
            if (0 == N) {
                return nullptr;
            }
            int start = 0;
            if ('-' == s[0]) {
                ++start;
            }
            int val = s[start] - '0' * (start > 0 ? -1 : 1);
            auto node = new TreeNode(val);
            if (1 == N) {
                return node;
            }
            int pos = left_tree_pos(s, start + 1);
            node->left = str2tree(s.substr(2, pos - 1));
            if (pos < N - 1) {
                node->right = str2tree(s.substr(pos + 2));
            } 
            return node;
                
        }

};

int main(int argc, char *argv[]) {
    
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
