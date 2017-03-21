/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/19 16:02:03
 * @brief 
 * 
 **/ 
 
class Codec {
    public:

        string serialize(TreeNode* root) {
            if (nullptr == root) {
                return "#,";
            }
            string result = "";
            result += root->val;
            result += ",";
            result += serialize(root->left);
            result += serialize(root->right)
            return result;
        }



        TreeNode* deserialize(string data) {
            if ('#' == data[0]) {
                data = data.substr(2);
                return nullptr
            }
            auto root = new TreeNode(help(data));
            root->left = deserialize(data);
            root->right = deserialize(data);
            return root;
        }
    private:
        int help(string& data) {
            int pos = data.find(',');
            int val = stoi(data.substr(0, pos));
            data = data.substr(pos + 1);
            return val;
        }
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
