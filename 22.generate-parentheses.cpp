/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (52.24%)
 * Total Accepted:    285.2K
 * Total Submissions: 545.5K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        dp.push_back({""});
        dp.push_back({"()"});
        for (int i = 2; i <= n; ++i) {
            // dp.push_back(vector<string>());
            dp.push_back({});
            for (auto& s : dp[i - 1]) {
                dp[i].push_back("(" + s + ")");
            }
            for (int j = 1; j <= i; ++j) {
                for (auto& prefix : dp[j]) {
                    for (auto& suffix : dp[i - j]) {
                        dp[i].push_back(prefix + suffix);
                    }
                }
            }
        }
        return dp[n];
    }
};
