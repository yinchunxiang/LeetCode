/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/04 12:43:06
 * @brief 
 * 
 **/ 

pair<int, int> robsub(TreeNode* root) {
    if (!root) {
        return make_pair(0, 0);
    }
    auto lc = robsub(root->left);
    auto rc = robusb(root->right);
    // rob root
    auto res0 = root->val + lc.second + rc.second;
    auto res1 = max(lc.first, lc.second) + max(rc.first, rc.second);
    return make_pair(res0, res1);
}
 
int rob(TreeNode* root) {
    auto p = robsub(root);
    return max(p.first, p.second);

}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
