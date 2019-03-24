//
// Created by yinchunxiang on 2019-03-23.
//

#include <iostream>
#include <sstream>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
 public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (nullptr == root) return "#";
    auto left = serialize(root->left);
    auto right = serialize(root->right);
    auto result = std::to_string(root->val) + " " + left + " " + right;
    std::cout << "serialize:" << result << std::endl;
    return result;
  }

  TreeNode* deserialize(istringstream& in) {
    string value;
    in >> value;
    std::cout << "value:" << value << std::endl;
    if (value == "#") {
      return nullptr;
    }
    TreeNode* node = new TreeNode(std::stoi(value));
    node->left = deserialize(in);
    node->right = deserialize(in);
    return node;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }


};

int main(int argc, const char *argv[]) {
  Codec codec;
  TreeNode* root = codec.deserialize("1 2 # # 3 4 # # 5 # #");
  std::cout << codec.serialize(root) << std::endl;
  return 0;
}

