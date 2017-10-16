/*
 * [691] Stickers to Spell Word
 *
 * https://leetcode.com/problems/stickers-to-spell-word
 *
 * algorithms
 * Hard (17.13%)
 * Total Accepted:    1.6K
 * Total Submissions: 5K
 * Testcase Example:  '["with","example","science"]\n"thehat"'
 *
 * 
 * We are given N different types of stickers.  Each sticker has a lowercase
 * English word on it.
 * 
 * You would like to spell out the given target string by cutting individual
 * letters from your collection of stickers and rearranging them.
 * 
 * You can use each sticker more than once if you want, and you have infinite
 * quantities of each sticker.
 * 
 * What is the minimum number of stickers that you need to spell out the
 * target?  If the task is impossible, return -1.
 * 
 * 
 * Example 1:
 * Input:
 * ["with", "example", "science"], "thehat"
 * 
 * 
 * Output:
 * 3
 * 
 * 
 * Explanation:
 * We can use 2 "with" stickers, and 1 "example" sticker.
 * After cutting and rearrange the letters of those stickers, we can form the
 * target "thehat".
 * Also, this is the minimum number of stickers necessary to form the target
 * string.
 * 
 * 
 * Example 2:
 * Input:
 * ["notice", "possible"], "basicbasic"
 * 
 * 
 * Output:
 * -1
 * 
 * 
 * Explanation:
 * We can't form the target "basicbasic" from cutting letters from the given
 * stickers.
 * 
 * 
 * Note:
 * stickers has length in the range [1, 50].
 * stickers consists of lowercase English words (without apostrophes).
 * target has length in the range [1, 15], and consists of lowercase English
 * letters.
 * In all test cases, all words were chosen randomly from the 1000 most common
 * US English words, and the target was chosen as a concatenation of two random
 * words.
 * The time limit may be more challenging than usual.  It is expected that a 50
 * sticker test case can be solved within 35ms on average.
 * 
 */

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>


using namespace std;


class Solve {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> mp(stickers.size(), vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            for (char c : stickers[i]) {
                mp[i][c - 'a'] ++;
            }
        }

        unordered_map<string, int> dp;
        dp[""] = 0;

        return help(mp, target, dp);
    }

    string toString(const vector<int>& target) {
        string result = "";
        for (int i = 0; i < 26; ++i) {
            int count = target[i];
            if (count <= 0) continue;
            result += string(count, 'a' + i);
        }
        return result;
    }

    int help(const vector<vector<int>>& mp, string target, unordered_map<string, int>& dp) {
        auto it = dp.find(target);
        if (dp.end() != it) {
            return it->second;
        }

        vector<int> targetVec(26, 0);
        for (char c : target) {
            targetVec[c - 'a'] ++;
        }

        int result = INT_MAX;

        int n = mp.size();
        for (int i = 0; i < n; ++i) {
            auto& stickerVec = mp[i];
            bool updated = false;
            vector<int> next(26, 0);
            for (int j = 0; j < 26; ++j) {
                next[j] = max(targetVec[j] - stickerVec[j], 0);
                if (next[j] != targetVec[j]) {
                    updated = true;
                }
            }
            if (!updated) continue;
            int tmp = help(mp, toString(next), dp);
            if (-1 == tmp) continue;
            result = min(result, 1 + tmp);
        }
        dp[target] = result == INT_MAX ? -1 : result;
        return dp[target];

    }
};

int main(int argc, char *argv[]) {
    vector<string> stickers = {"with", "example", "science"};
    string target = "thehat";
    Solve s;
    cout << s.minStickers(stickers, target) << endl;
    return 0;
}

