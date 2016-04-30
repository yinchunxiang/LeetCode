#include <iostream> 
#include <vector> 

using namespace std;


class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> sub;
            dfs(result, sub, nums, 0);
            return result;
        }

        void dfs(vector<vector<int>>& result, vector<int> sub, const vector<int>& nums, int index) {
            if (index >= num.size()) {
                result.push_back(sub);
                return;
            }
            if (index == 0 || nums[index] != nums[index - 1]) {
                dfs(result, sub, nums, index + 1);
            }
            sub.push_back(nums[index]);
            dfs(result, sub, nums, index + 1);
        }

};

int main(int argc, const char *argv[])
{
    vector<>
    return 0;
}


