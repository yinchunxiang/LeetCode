#include <iostream>
#include <vector>   
#include <queue> 
#include <utility> 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* build_tree(vector<int>& inorder, int start1, int end1, vector<int>& postorder, int start2, int end2) {
    if (start1 > end1 || start2 > end2){
        return NULL;
    }

    TreeNode* parent = new TreeNode(postorder[end2]);
    
    int left_count = 0;
    int i = start1;
    while(inorder[i++] != postorder[end2]) {
        left_count ++;
    }
    int right_count = end1 - start1 - left_count;
    int mid1 = start1 + left_count;
    
    TreeNode* lc = NULL;
    if (left_count >0 ) {
        lc = build_tree(inorder, start1, mid1 - 1, postorder, start2, start2 + left_count - 1);
    }

    TreeNode* rc = NULL;
    if (right_count > 0) {
        rc = build_tree(inorder, mid1 + 1, end1, postorder, start2 + left_count, end2 - 1);
    }

    parent->left = lc;
    parent->right = rc;
    return parent;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build_tree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

void level_traverse(TreeNode* root) {
    queue<TreeNode*> curr_level;
    queue<TreeNode*> next_level;
    curr_level.push(root);
    while (!curr_level.empty()) {
        while( !curr_level.empty() ) {
            TreeNode* node = curr_level.front();
            curr_level.pop();
            cout << node->val << " " ;
            if (node->left) {
                next_level.push(node->left);
            }
            if (node->right) {
                next_level.push(node->right);
            }
        }
        cout << endl;
        swap(curr_level, next_level);
    }
    cout << endl;

}
int main(int argc, const char *argv[])
{
    int a[] = {2,1};
    int b[] = {1,2};
    vector<int> inorder(a, a+2);
    vector<int> postorder(b, b+2);
    TreeNode* root = buildTree(inorder, postorder);
    level_traverse(root);
    return 0;
}



