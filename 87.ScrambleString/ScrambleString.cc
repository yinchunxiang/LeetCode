/****************************************************************************
 * 
 * Copyright (C) 2016 Baidu.com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file ScrambleString.cc
 * @author yinchunxiang(com@baidu.com)
 * @date 2016/03/19 23:11:24
 * @brief 
 * 
 **/ 
 
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> scramble(const string& s) {
    unordered_set<string> result;
    int size = s.size();
    if (size <= 1) {
        result.insert(s);
        return result;
    }

    for (int i = 1; i < size; ++i) {
        auto front_half = scramble(s.substr(0, i));
        auto back_half = scramble(s.substr(i));
        for (auto& fh : front_half) {
            for (auto& bh : back_half) {
                result.insert(bh + fh);
                result.insert(fh + bh);
            }
        }
    }
    return result;
}

int main(int argc, const char *argv[])
{

    //auto s = scramble("greatgreatgreatgreatgreatgreatgreatgreatgreatgreatgreat");
    auto s = scramble("greatxxxxyyyy");
    //for (auto& str : s) {
    //    cout << str << endl;
    //}
    if (s.find("egartxxxxyyyy") == s.end()) {
        cout << "false" << endl;
    } else {
        cout << "true" << endl;
    }
    
    
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
