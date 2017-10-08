/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file dfs.cc
 * @author yinchunxiang(@com)
 * @date 2017/10/08 18:42:16
 * @brief 
 * 
 **/ 

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    int maxCount = 6;
    public:
        int findMinStep(string board, string hand) {
            if (board.empty()) return 0;
            if (hand.empty()) return -1;
            vector<int> handBallCount(26, 0);
            for (char c : hand) {
                handBallCount[c - 'A'] += 1;
            }

            for (int i = 0; i < handBallCount.size(); ++i) {
                if (handBallCount[i] <= 0) continue;
                cout << char('A' + i) << " => " << handBallCount[i] << endl;
            }



            int result = dfs(board + "#", handBallCount);
            return result == maxCount ? -1 : result;
        }

        string removeConsecutive(string board) {
            for(int start = 0, end = 0; end < board.size(); ++end) {
                if (board[start] == board[end]) {
                    continue;
                }
                if (end - start >= 3) {
                    return removeConsecutive(board.substr(0, start) + board.substr(end));
                }
                start = end;
            }
            return board;
        }

        int dfs(string board, vector<int>& handBallCount) {
            int size = board.size();
            if (1 == size) return 0;
            int result = maxCount;
            for(int start = 0, end = 0; end < size; ++end) {
                if (board[start] == board[end]) {
                    continue;
                }
                int need = 3 - (end - start);
                int ball = board[start] - 'A';
                int had = handBallCount[ball];
                if (had >= need) {
                    handBallCount[ball] -= need;
                    string nextBoard = removeConsecutive( board.substr(0, start) + board.substr(end) );
                    result = min(result, need + dfs(nextBoard, handBallCount));
                    handBallCount[ball] += need;
                }
                start = end;
            }
            return result;
        }

};


int main(int argc, char *argv[])
{
    Solution s;
    cout << s.findMinStep("WWRRBBWW", "WRBRW");
    
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
