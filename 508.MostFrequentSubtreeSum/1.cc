/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/03/15 23:00:57
 * @brief 
 * 
 **/ 
 
class Solution {
    public:
        int traverse(TreeNode* root) {
            if (nullptr == root) {
                return 0;
            }
            int sum = root->val + traverse(root->left) + traverse(root->right);
            int &count = sum_count_map_[sum];
            count += 1;
            if (count > maxf_) {
                maxf_ = count;
            }
            return sum;
        }
        vector<int> findFrequentTreeSum(TreeNode* root) {
            traverse(root);
            vector<int> result;
            for (auto p : sum_count_map_) {
                if (p.second == maxf_) {
                    result.push_back(p.first);
                }
            }
            return result;
        }

    private:
        unordered_map<int, int> sum_count_map_;
        int maxf_ = 0;

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
