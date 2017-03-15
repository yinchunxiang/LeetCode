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
            if (count > count_nums_vec_.size()) {
                count_nums_vec_.push_back(vector<int>{sum});
            } else {
                count_nums_vec_[count].push_back(sum);
            }
            return sum;
        }
        vector<int> findFrequentTreeSum(TreeNode* root) {
            if (nullptr == root) {
                return vector<int>();
            }
            traverse(root);
            return count_nums_vec_.back();
        }

    private:
        unordered_map<int, int> sum_count_map_;
        vector<vector<int>> count_nums_vec_;

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
