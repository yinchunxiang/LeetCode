/****************************************************************************
 * 
 * Copyright (C) 2017 @com, Inc. All rights reserved.
 * 
 ****************************************************************************/



/** 
 * @file main.cc
 * @author yinchunxiang(@com)
 * @date 2017/09/10 12:27:59
 * @brief 
 * 
 **/

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  // 这个方法是个非常trick的方法
  string minWindow(string s, string t) {
    vector<int> m(256, 0);
    int count = 0; // 代表缺少的元素的总个数
    for (auto c : t) {
      m[c] += 1; // m[c]: 正数代表当前缺少的 c 元素的个数, 负数代表当前富裕的 c 元素的个数
      count += 1;
    }
    // 找到第一个窗口
    int start = 0;
    int end = 0;
    int d = s.size() + 1;
    int begin = 0;
    for (int end = 0; end < s.size(); ++end) {
      auto c = s[end];
      // 注意：这里不管是不是t里面包含的元素，都进行了减操作
      if (m[c]-- > 0) {
        count -= 1;
      }
      if (count) continue;
      for (; start <= end; ++start) {
        auto c = s[start];
        // 代表的都是富裕的元素
        if (m[c]++ < 0) continue;
        break;
      }
      if (end - start + 1 < d) {
        d = end + 1 - (begin = start);
      }
    }

    return d > s.size() ? "" : s.substr(begin, d);
  }

};













/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
