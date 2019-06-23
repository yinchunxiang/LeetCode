//
// Created by alexkkk on 2019-06-09.
//

class Solution {
public:
  // 经过节点的最大值
  bool dfs(TreeNode *node, int pre, int limit) {
    if (nullptr == node)  return pre >= limit;
    auto ls = dfs(node->left, pre + node->val, limit);
    if (!ls) node->left = nullptr;
    auto rs = dfs(node->right, pre + node->val, limit);
    if (!rs) node->right = nullptr;
    return ls || rs;
  }

  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    if (nullptr == root) return root;
    auto ret = dfs(root, 0, limit);
    if (!ret) return nullptr;
    return root;

  }
}

