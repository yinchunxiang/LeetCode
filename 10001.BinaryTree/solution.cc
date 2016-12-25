/****************************************************************************
 * 
 * Copyright (C) 2016 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file solution.cc
 * @author yinchunxiang(@com)
 * @date 2016/06/19 23:59:34
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
void println(const char* c) {
    std::cout << "{" << c << "}" << std::endl;
}

void println(const std::string& str) {
    std::cout << "{" << str << "}" << std::endl;
}

void println(const char& c) {
    std::cout << "{" << c << "}" << std::endl;
}

template<typename T>
void println(const T& t) {
    std::cout << "{" << std::to_string(t) << "}" << std::endl;
}

class Tree {
    public:
        struct Node {
            int val;
            Node *left;
            Node *right;
            Node(int x) : val(x), left(nullptr), right(nullptr) {}
        };

        ///{1, 2, 3, 4, INT_MAX, INT_MAX, 5} 表示的树如下
        //             1
        //            / \
        //           2   3
        //          /     \
        //         4       5
        Tree(const std::vector<int>& vec) {
            if (vec.empty()) return;
            size_t size = vec.size();
            vector<Node*> nodes(size, nullptr);
            for (auto i = 0; i < size; ++i) {
                if (INT_MAX == vec[i]) continue;
                nodes[i] = new Node(vec[i]);
            }
            for (auto node : nodes) {
                if (nullptr == node) {
                    cout << "NULL ";
                } else {
                    cout << node->val << " ";
                }
            }
            cout << endl;
            for (auto i = 0; i < size; ++i) {
                int lc = (i << 1) + 1;
                int rc = (i << 1) + 2;
                if (lc < size) {
                    nodes[i]->left = nodes[lc];
                }
                if (rc < size) {
                    nodes[i]->right = nodes[rc];
                }
                cout << "lc:" << lc << " rc:" << rc  << endl;
            }
            root_ = nodes[0];
        }
        
        void print_by_level() {
            if (nullptr == root_) {
                println("NULL");
                return;
            }
            vector<Node*> cur_level;
            vector<Node*> next_level;
            cur_level.push_back(root_);
            while (!cur_level.empty()) {
                for (auto node : cur_level) {
                    if (nullptr == node) {
                        cout << "N\t";
                    } else {
                        cout << node->val << "\t";
                        next_level.push_back(node->left);
                        next_level.push_back(node->right);
                    }
                }
                cout << endl;
                cur_level.clear();
                cur_level.swap(next_level);
            }
        }

        ~Tree() {
            release(root_);
        }

        void preorder_recursive() {
        }

        void preorder_nonrecursive() {
            if (nullptr == root_) return;
            stack<const Node*> s;
            s.push(root_);
            const Node* p = nullptr;
            while (!s.empty()) {
                p = s.top();
                s.pop();
                println(p->val);
                if (p->right) {
                    s.push(p->right);
                }
                if (p->left) {
                    s.push(p->left);
                }
            }
        }
        
        void preorder_morris() {
            if (!root_) return;
            auto p = root_;
            while (p) {
                if (!p->left) {
                    println(p->val);
                    p = p->right;
                } else {
                    auto temp = p->left;
                    while (p != temp->right && temp->right) {
                        temp = temp->right;
                    }
                    if (!temp->right) {
                        ///第一次从左子的最右节点返回，直接访问节点
                        println(p->val);
                        temp->right = p;
                        p = p->left;
                    } else {
                        ///第二次从左子的最右节点返回，已经都完成访问
                        ///拆开廉洁，同时转向访问右子
                        temp->right = nullptr;
                        p = p->right;
                    }
                    
                }
            }
        }

        void inorder_nonrecursive() {
            if (nullptr == root_) return;
            stack<const Node*> s;
            const Node* p = root_;
            while (!s.empty() || nullptr != p) {
                if (nullptr != p) {
                    s.push(p);
                    p = p->left;
                } else {
                ///出栈的时候代表要被访问了
                ///根比左节点后出栈
                    p = s.top();
                    s.pop();
                    println(p->val);
                    p = p->right;
                }
            }
        }

        void inorder_nonrecursive_mod() {
            if (nullptr == root_) return;
            stack<Node*> s;
            s.push(root_);
            while (!s.empty()) {
                auto node = s.top();
                while (node->left) {
                    s.push(node->left);
                    ///这种方法不好，改变了树的结构
                    node->left = nullptr;
                    node = s.top();
                }
                println(node->val);
                s.pop();
                if (node->right) {
                    s.push(node->right);
                }
            }
        }

        ///时间复杂度O(N), 空间复杂度O(1)
        ///时间换空间
        void inorder_morris() {
            if (nullptr == root_) return;
            auto p = root_;
            while (p) {
                if (nullptr == p->left) {
                    cout << p->val << endl;
                    p = p->right;
                } else {
                    auto temp = p->left;
                    while (nullptr != temp->right && p != temp->right) {
                        temp = temp->right;
                    }
                    if (nullptr == temp->right) {
                        ///第一次访问节点p，p的左子还没有访问
                        ///需要先访问p的左子
                        temp->right = p;
                        p = p->left;
                    } else {
                        ///p的左子已经访问完成，访问p本身，再访问p的右子
                        ///要将原来建立的连接断开
                        cout << p->val << endl;
                        temp->right = nullptr;
                        p = p->right;
                    }
                }
            }
        }
        
        /// 时间复杂度O(N), 空间复杂度O(N)
        void postorder_nonrecursive() {
            if (nullptr == root_) return;
            const Node* pre = nullptr;
            const Node* cur = root_;
            stack<const Node*> s;
            do {
                ///一直往左走进行入栈
                while (cur) {
                    s.push(cur);
                    cur = cur->left;
                }
                pre = nullptr;
                ///当没有可入栈的时候，开始弹栈
                while (!s.empty()) {
                    cur = s.top();
                    ///表示从右节点返回,或者右节点为空,
                    ///则开始访问当前节点,并继续弹栈
                    if (cur->right == pre) {
                        println(cur->val);
                        pre = cur; ///保存刚刚访问过的节点
                        s.pop();
                    } else { ///从左节点返回,表示不能处理，要继续进行入栈
                        ///当前节点不能访问，需要二次进栈
                        //s.push(cur);
                        ///处理右节点，继续进行入栈
                        cur = cur->right;
                        break;
                    }
                }
            } while (!s.empty());
        }

        void reverse(Node* from, Node* to) {
            Node* pre = nullptr;
            Node* cur = from;
            Node* temp = nullptr;
            while (to != pre) {
                temp = cur;
                cur = cur->right;
                temp->right = pre;
                pre = temp;
            }
        }

        void print_reverse(Node* from, Node* to) {
            cout << "from " << from->val << " to " << to->val << endl;
            if (from == to) {
                cout << from->val << endl;
                return;
            }
            reverse(from, to);
            for (auto p = to; p != nullptr; p = p->right) {
                cout << p->val << endl;
            }
            reverse(to, from);
        }

        void postorder_morris() {
            if (!root_) return;
            Node dummy(-1);
            dummy.left = root_;
            auto p = &dummy;
            while (p) {
                if (!p->left) {
                    p = p->right;
                } else {
                    auto temp = p->left;
                    while (temp->right && p != temp->right) {
                        temp = temp->right;
                    }
                    if (!temp->right) {
                        //第一次从左子的最右节点返回，继续处理左子
                        temp->right = p;
                        p = p->left;
                    } else {
                        //第二次从左子的最右节点返回，反向输出节点
                        //断开之前建立的连接，并转向处理右子
                        print_reverse(p->left, temp);
                        temp->right = nullptr;
                        p = p->right;
                    }
                }
            }
        }

        

        void release(Node* &root) {
            if (nullptr == root) return;
            release(root->left);
            release(root->right);
            delete(root);
            root = nullptr;
        }
    private:
        Node *root_ = nullptr;

};

int main(int argc, const char* argv[]) {
    vector<int> v = {1, 2, 3, 4, INT_MAX, INT_MAX, 5};
    Tree tree(v);
    println("print_by_level ======>");
    tree.print_by_level();
    println("preorder_morris ======>");
    tree.preorder_morris();
    println("inorder_nonrecursive ======>");
    tree.inorder_nonrecursive();
    println("inorder_morris ======>");
    tree.inorder_morris();
    println("postorder_nonrecursive ====>");
    tree.postorder_nonrecursive();
    println("postorder_morris ====>");
    tree.postorder_morris();
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
