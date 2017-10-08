/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file test.cc
 * @author yinchunxiang(@com)
 * @date 2017/10/08 18:33:34
 * @brief 
 * 
 **/ 

#include <iostream>
#include <string>

using namespace std;
 
string removeConsecutive(string board) {
    for (int i = 0, j = 0; j < board.length(); ++j) {
        if (board[j] == board[i]) continue;
        if (j - i >= 3) return removeConsecutive(board.substr(0, i) + board.substr(j));
        else i = j;
    }
    return board;
}

int main(int argc, char *argv[]) {
    string board = "aaaaaa";
    cout << removeConsecutive(board) << endl;
    return 0;
}













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
