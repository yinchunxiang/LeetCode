/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 21:37:34
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>

using namespace std;

typedef vector<int>::iterator It;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
    public:
        TreeNode* bt(It inBegin, It inEnd, It postBegin, It postEnd) {
            if (inBegin == inEnd) {
                return nullptr;
            }
            if (next(inBegin) == inEnd) {
                return new TreeNode(*inBegin);
            }
            auto postRootIt = prev(postEnd);
            auto inRootIt = find(inBegin, inEnd, *postRootIt);
            auto root = new TreeNode(*postRootIt);
            int d = distance(inBegin, inRootIt);
            It postLeftEnd = postBegin + d;
            root->left = bt(inBegin, inRootIt, postBegin, postBegin + d);
            root->right = bt(next(inRootIt), inEnd, postLeftEnd, prev(postEnd));
            return root;
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return bt(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
        }


};

void preorder(TreeNode* root) {
    if (nullptr == root) return;
    cout << "root => " << root->val << endl;
    cout << "left => " << endl;
    preorder(root->left);
    cout << "right => " << endl;
    preorder(root->right);
}

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> in = {3, 2, 1};
        vector<int> post = {3, 2, 1};
        auto root = s.buildTree(in, post);
        preorder(root);

    }
    
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
