/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file 2.cc
 * @author yinchunxiang(@com)
 * @date 2017/04/08 18:01:03
 * @brief 
 * 
 **/ 

{

int calc(string& str) {
    int a = 0; //不匹配的左括号
    int b = 0; //不匹配的右括号
    for (auto c : str) {
        if ('(' == c) {
            ++a;
            break;
        }
        if (')' == c) {
            --a;
            if (a < 0) {
                ++b;
                a = 0;
            }
            break;
        }
    }
    return a + b;
}
 
vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    queue<string> q;
    q.push(s);
    unordered_set<string> visited;
    visited.insert(s);
    bool found = false;
    while (!q.empty()) {
        str = q.front();
        q.pop();
        int count = calc(str);
        if (!count) {
            result.push_back(str);
            found = true;
        }
        if (found) {
            continue;
        }
        for (int i = 0; i < str.size(); ++i) {
            if ('(' != str[i] && ')' != str[i]) {
                continue;
            }
            string next = str.substr(0, i) + str.substr(i + 1);
            if (visited.end() == visited.find(next) && calc(next) < count) {
                q.push(next);
                visited.insert(next);
            }
        }
    }

}







}





/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
