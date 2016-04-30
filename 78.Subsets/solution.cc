#include <iostream> 
#include <vector> 

using namespace std;


class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> sub;
            int size = nums.size();
            dfs(result, sub, v, 0);
            return result;
        }

        void dfs(vector<vector<int>>& result, vector<int> sub, const vector<int>& v, int index) {
            if (index >= v.size()) return;
            result.push_back(sub);
            dfs(result, sub, v, index + 1);
            sub.push_back(v[index]);
            result.push_back(sub);
            dfs(result, sub, v, index + 1);
        }
};


int main(int argc, const char *argv[])
{
    
    return 0;
}
