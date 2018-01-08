//
// Created by alexkkk on 12/10/17.
//

#include <unordered_map>
#include <iostream>
#include <zconf.h>
#include "../util/tree.h"

using namespace std;

struct Info {
    Info() {}
    Info(TreeNode* parent, TreeNode *leaf, int height, int lr)
            : parent_(parent), leaf_(leaf), height_(height), lr_(lr) {
    }
    TreeNode *parent_ = nullptr;
    TreeNode *leaf_ = nullptr;
    int height_ = 0;
    int lr_ = -1;
};

class Solution {
public:

    // 返回根节点到叶子节点的最短距离
    Info* traverse(TreeNode* root, TreeNode* parent, int lr) {
        //leaf
        if (nullptr == root->left && nullptr == root->right) {
            Info *info = new Info(parent, root, 0, lr);
            m[root->val] = info;
            return info;
        }

        Info* li = nullptr;
        Info* ri = nullptr;
        if (root->left) {
            li = traverse(root->left, root, 0);
        }
        if (root->right) {
            ri = traverse(root->right, root, 1);
        }

        Info *info = nullptr;
        if (nullptr == li)  {
            info = new Info(parent, ri->leaf_, ri->height_ + 1, lr);
            m[root->val] = info;
            return info;
        }

        if (nullptr == ri) {
            info = new Info(parent, li->leaf_, li->height_ + 1, lr);
            m[root->val] = info;
            return info;
        }

        if (li->height_ < ri->height_) {
            info = new Info(parent, li->leaf_, li->height_ + 1, lr);
        } else {
            info = new Info(parent, ri->leaf_, ri->height_ + 1, lr);
        }
        m[root->val] = info;
        return info;
    }

    int findClosestLeaf(TreeNode* root, int k) {
        traverse(root, nullptr, -1);
        Info *info = m[k];
        if (nullptr == info->parent_) {
            return info->leaf_->val;
        }
        int key = -1;
        //是父亲的左子
        if (0 == info->lr_) {
            key = info->parent_->right->val;
        } else {
            key = info->parent_->left->val;
        }
        Info *other = m[key];
        if (info->height_ < other->height_ + 2) {
            return info->leaf_->val;
        } else {
            return other->leaf_->val;
        }

    }

private:
    unordered_map<int, Info*> m;
};

int main(int argc, char* argv[]) {
    {
        vector<string> input = {"1","2","3","4","null","null","null","5","null","6"};
        TreeNode *tree = TreeNode::create(input);
        if (nullptr == tree) cout << "null root " << endl;
        cout << "tree: " << tree->val << endl;
        print(tree);
    }

    //TODO
    /*
    {
        vector<string> input = {"1", "2"};
        TreeNode *tree = TreeNode::create(input);

        Solution s;
        cout << s.findClosestLeaf(tree, 1) << endl;
    }
    {
        vector<string> input = {"1", "2", "3", "null", "null", "4", "5", "6", "null", "null", "7", "8", "9", "10"};
        TreeNode *tree = TreeNode::create(input);
        print(tree);

        Solution s;
        cout << s.findClosestLeaf(tree, 2) << endl;
    }
     */

    return 0;
}
