#include <iostream>
#include <vector> 
#include <stack> 


using namespace std;

struct TreeNode {
    int value_;
    TreeNode* left_;
    TreeNode* right_;
    TreeNode(int value) : value_(value), left_(NULL), right_(NULL) {}
    TreeNode() : value_(0), left_(NULL), right_(NULL) {}
};

class Tree {
    public:
        Tree(int num) : root_(vector<TreeNode>(num, TreeNode())) {
            for (int i = 0; i < num; ++i) {
                root_[i].value_ = i + 1;
                int lc = 2*i + 1;
                if (lc < num) {
                    root_[i].left_ = &root_[lc];
                }
                int rc = lc + 1;
                if (rc < num) {
                    root_[i].right_ = &root_[rc];
                }
            }
        }

        void Traverse() {
            TreeNode* root = &root_[0];
            stack<TreeNode*> s;
            while (!s.empty() || root) {
                if (root) {
                    cout << root->value_ << " ";
                    s.push(root);
                    root = root->left_;
                }
                else {
                    TreeNode* parent = s.top();
                    if (parent->right_) {
                        root = parent->right_;
                    }
                    s.pop();
                }
            }
        }
        void flatten() {
            TreeNode* root = &root_[0];
            stack<TreeNode*> s;
            TreeNode dummy(-1);
            TreeNode* tail = &dummy
            while (!s.empty() || root) {

            }
        }
    private:
    vector<TreeNode> root_;

};

int main(int argc, const char *argv[])
{
    Tree tree(10); 
    tree.Traverse();
    return 0;
}



