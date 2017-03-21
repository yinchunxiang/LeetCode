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
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
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
    TreeNode* deserialize(string& data, int pos, int lower, int upper) {
        if (pos >= data.size()) {
            return nullptr;
        }

        int i = pos;
        int number = 0;
        while (' ' != data[i]) {
            number = 10 * number + (data[i] - '0');
            ++i;
        }
        if (number < lower || number > upper) {
            return nullptr;
        }
        pos = ++i;
        auto root = new TreeNode(*l);
        root->left = deserialize(data, pos, lower, root->val);
        root->right = deserialize(data, pos, root->val, upper);
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
