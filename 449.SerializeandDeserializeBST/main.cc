/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/16 20:22:21
 * @brief * 
 **/ 

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void printv(const std::vector<int> &v) {
    for (const auto &i: v) {
        cout << i << " ";
    }
    cout << endl;
}
 
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string serialize(TreeNode* root)  {
        ostringstream out;
        serialize(root, out);
        return out.str();

    }
    TreeNode* deserialize(string data) {
        istringstream in(data);
        vector<int> v;
        string val;
        while (in >> val) {
            v.push_back(stoi(val));
        }
        printv(v);
        return deserialize(begin(v), end(v));

    }

private:

    // Encodes a tree to a single string.
    void serialize(TreeNode* root, ostringstream& out) {
        if (nullptr == root) {
            return ;
        }
        out << std::to_string(root->val) << " ";
        out << serialize(root->left);
        out << serialize(root->right);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(vector<int>::iterator l, vector<int>::iterator r) {
        if (l == r) {
            return nullptr;
        }
        cout << "create node => " << *l << endl;
        auto root = new TreeNode(*l);
        auto rbegin = upper_bound(l, r, *l);
        root->left = deserialize(next(l), rbegin);
        root->right = deserialize(rbegin, r);
        return root;
    }

};

int main(int argc, char *argv[]) {
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    Codec c;
    auto s = c.serialize(root) ;
    cout << s << endl;
    c.deserialize(s);
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
