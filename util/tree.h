//
// Created by alexkkk on 12/10/17.
//

#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <list>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    static TreeNode* create(const std::vector<std::string>& input) {
        std::cout << "--------> create start " << std::endl;
        if (input.empty()) return nullptr;
        std::list<TreeNode*> treeNodeList;
        for (auto& str : input) {
            if ("null" == str) {
                treeNodeList.push_back(nullptr);
                continue;
            }
            int val = atoi(str.c_str());
            treeNodeList.push_back(new TreeNode(val));
        }
        for (auto& node : treeNodeList) {
            if (nullptr == node) {
                std::cout << "null " << std::endl;
                continue;
            }
            std::cout << node->val << std::endl;
        }

        TreeNode* root = treeNodeList.front();
        std::queue<TreeNode*> current;
        std::queue<TreeNode*> next;
        current.push(treeNodeList.front()); treeNodeList.pop_front();

        while (!current.empty()) {
            while (!current.empty()) {
                auto& node = current.front();
                std::cout << "---> in create " << node->val << " " << std::endl;
                auto left = treeNodeList.front();
                treeNodeList.pop_front();
                node->left = left;
                if (left) next.push(left);

                auto right = treeNodeList.front();
                treeNodeList.pop_front();
                node->right = right;
                if (right) next.push(right);

                current.pop();
            }
            current.swap(next);
        }

        std::cout << "--------> create end " << std::endl;
        return root;

    }

};

void print(TreeNode* root) {
    std::cout << "--------> print start " << std::endl;
    return;
    /*
    if (nullptr == root) {
        std::cout << "null tree" << std::endl;
        return;
    }

    std::queue<TreeNode*> current;
    current.push(root);
    std::queue<TreeNode*> next;
    while (!current.empty()) {
        //print current level
        while (!current.empty()) {
            auto node = current.front();
            std::cout << node->val << " ";
            if (node->left) {
                next.push(node->left);
                std::cout << "add " << node->left->val << std::endl;
            }
            if (node->right) {
                next.push(node->right);
                std::cout << "add " << node->right->val << std::endl;
            }
            current.pop();
        }
        std::cout << std::endl;
        current.swap(next);
    }
     */
}



#endif //LEETCODE_TREE_H
