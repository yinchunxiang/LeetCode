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
#include <vector>
#include <algorithm>

using namespace std;

bool ok(const std::string& s1, const std::string& s2) {
    vector<int> v(256, 0);
    for (auto& ch : s1) {
        ///cout << "ch:" << ch << endl;
        v[ch] += 1;
        //cout << "v[ch]:" << v[ch] << endl;
    }
    for (auto& ch : s2) {
        //cout << "ch:" << ch << endl;
        v[ch] -= 1;
        //cout << "v[ch]:" << v[ch] << endl;
    }
    //for (auto& c : v) {
    //    if (c != 0) {
    //        cout << c << endl;
    //    }
    //}
    return !std::any_of(v.begin(), v.end(), [](int i) {return i != 0;});
}

bool  is_scramble(const std::string& s1, const std::string& s2) {
    int size1 = s1.size();
    int size2 = s2.size();
    if (size1 != size2) {
        return false;
    }
    if (size1 <= 1) {
        return s1 == s2;
    }

    if (!ok(s1, s2)) {
        return false;
    }
    //bool result = false;
    for (int i = 1; i < size1; ++i) {
        auto front_half = s1.substr(0, i);
        auto back_half = s1.substr(i);
        auto fh1 = s2.substr(0, i);
        auto bh1 = s2.substr(i);
        if (is_scramble(front_half, fh1) && is_scramble(back_half, bh1)) {
            return true;
        }
        auto fh2 = s2.substr(0, size1 - i);
        auto bh2 = s2.substr(size1 - i);
        if (is_scramble(front_half, bh2) && is_scramble(back_half, fh2)) {
            return true;
        }

    }
    return false;
}

int main(int argc, const char *argv[])
{

    ///auto ret  = is_scramble("greatgreatgreatgreatgreatgreatgreatgreatgreatgreatgreat", "egartgreatgreatgreatgreatgreatgreatgreatgreatgreatgreat");
    auto ret  = is_scramble("greatxxxxyyyy", "egartxxxxyyyy");
    //if (ok("aa", "aa")) {
    //    cout << "OK" << endl;
    //} else {
    //    cout << "NOK" << endl;
    //}
    //auto ret  = is_scramble("aa", "aa");
    if (ret) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}














/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
