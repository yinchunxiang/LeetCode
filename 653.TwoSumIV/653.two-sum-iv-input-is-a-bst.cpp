/*
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst
 *
 * algorithms
 * Easy (50.74%)
 * Total Accepted:    16.1K
 * Total Submissions: 31.7K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void treeToList(vector<int>& result, TreeNode* root) {
        if (nullptr == root) {
            return;
        }
        treeToList(result, root->left);
        result.push_back(root->val);
        treeToList(result, root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> treeList;
        treeToList(treeList, root);
        int low = 0; 
        int high = treeList.size() - 1;
        while (low < high) {
            int sum = treeList[low] + treeList[high];
            if (sum == k) {
                return true;
            }
            if (sum > k) {
                --high;
            } else {
                ++low;
            }
        }
        return false;
        
    }
};
