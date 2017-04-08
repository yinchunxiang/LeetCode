/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/05 16:21:46
 * @brief 
 * 
 **/ 

#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;
 
class Solution {
    public:
        bool dfs(int &minballs, string board, unordered_set<int> used, const string& hand, int index, int level) {
            cout << "enter board: " << board << endl;
            if (board.empty()) {
                minballs = min(minballs, level);
                return true;
            }
            if (level >= hand.size()) {
                return board.empty();
            }
            ++level;

            used.insert(index);
            bool found = false;

            for (int i = 0; i < board.size() + 1; ++i) {
                string nb;
                if (0 == i)  {
                    if (i + 1 < board.size() && hand[index] == board[i] && hand[index] == board[i + 1]) {
                        nb = board.substr(i + 2);
                    } else {
                        nb = hand[index] + board;
                    }
                }
                
                if (board.size() - 1 == i) {
                    if (i - 1 > 0 && hand[index] == board[i] && hand[index] == board[i - 1]) {
                        nb = board.substr(0, i - 1);
                    } else {
                        nb = board + hand[index];
                    }

                }
                if (board[i - 1] == hand[index] && board[i] == hand[index]) {
                    nb = board.substr(0,  i - 1) + board.substr(i + 1);
                } else {
                    nb = board.substr(0, 1) + hand[index] + board.substr(i);
                }
                cout << "======> nb:" << nb << endl;
                for (int i = 0; i < hand.size(); ++i) {
                    if (used.end() != used.find(i)) {
                        continue;
                    }
                    if (dfs(minballs, nb, used, hand, i, level)) {
                        found = true;
                    }
                }
            }
            return found;
        }
        int findMinStep(string board, string hand) {
            int minballs = hand.size();
            bool found = false;
            for (int i = 0; i < hand.size(); ++i) {
                if (dfs(minballs, board, {}, hand, i, 0)) {
                    found = true;
                }
            }
            if (found) {
                return minballs;
            }
            return -1;
        }

};


int main(int argc, char *argv[]) {
    Solution s;
    /*
    {
        string board = "WRRBBW";
        string hand = "RB";
        cout << s.findMinStep(board, hand) << endl;
    }
    */
    {
        string board = "WWRRBBWW";
        string hand = "WRBRW";
        cout << s.findMinStep(board, hand) << endl;
    }
    /*
    {
        string board = "G";
        string hand = "GGGGG";
        cout << s.findMinStep(board, hand) << endl;
    }
    {
        string board = "RBYYBBRRB";
        string hand = "YRBGB";
        cout << s.findMinStep(board, hand) << endl;
    }
    */
    return 0;
}









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
