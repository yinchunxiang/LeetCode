#include <iostream>
#include <vector>
#include <queue>
#include <utility>



using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* sorted_array_to_bst(vector<int> &num, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    TreeNode* lc = sorted_array_to_bst(num, start, mid - 1);
    TreeNode* rc = sorted_array_to_bst(num, mid + 1, end);
    TreeNode* parent = new TreeNode(num[mid]);
    parent->left = lc;
    parent->right = rc;
    return parent;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    return sorted_array_to_bst(num, 0, num.size() - 1);
}

void level_traverse(TreeNode* root) {
    queue<TreeNode*> curr_level;
    queue<TreeNode*> next_level;

    curr_level.push(root);
    while( !curr_level.empty() ){
        while( !curr_level.empty() ) {
            TreeNode* node = curr_level.front();
            curr_level.pop();
            if(node->left) {
                next_level.push(node->left);
            }
            if (node->right) {
                next_level.push(node->right);
            }

            cout << node->val << " ";
        }
        cout << endl;
        swap(curr_level, next_level);        
    }
    cout << endl;

}

int main(int argc, const char *argv[])
{
    vector<int> numbers(6);
    for( int i = 1; i < 6; ++i){
        numbers[i] = i;
    }

    TreeNode* root = sortedArrayToBST(numbers);
    if (NULL == root) {
        cout << "root is null" << endl;
        return -1;
    }
    level_traverse(root);
    
    return 0;
}
