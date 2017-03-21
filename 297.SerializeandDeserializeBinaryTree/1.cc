/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 1.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/19 16:29:27
 * @brief 
 * 
 **/ 

class Codec {
    public:

        string serialize(TreeNode* root) {
            ostringstream out;
            serialize(root, out);
            return out.str();

        }

        TreeNode* deserialize(string data) {
            istringstream in(data);
            return deserialize(in);

        }

priavte:
        void serialize(TreeNode* root, ostringstream &out) {
            if (nullptr == root) {
                out << "#";
            }
            out << root->value << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }

        TreeNode* deserialize(istringstream &in) {
            string val;
            in >> val;
            if ("#" == val) {
                return nullptr;
            }
            auto root = new TreeNode(atoi(val.c_str()));
            root->left = deserialize(in);
            root->right = deserialize(in);
            return root;
        }
};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
