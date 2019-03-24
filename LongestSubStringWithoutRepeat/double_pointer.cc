//
// Created by yinchunxiang on 2019-03-03.
//

// 双指针法
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n < 2) return n;
    vector<int> count(256, 0);
    int d = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
      auto c = s[i];
      //cout << i << " => " << s[i] << endl;
      count[c] += 1;
      if (1 == count[c]) {
        d = max(d, i - start + 1);
        //cout << "111 -> start => " << start << endl;
        continue;
      }
      for (; start <= i; ++start) {
        auto c = s[start];
        count[c] -= 1;
        if (1 == count[c]) break;
      }
      //cout << "222 -> start => " << start << endl;
      d = max(d, i - start);
      ++start;
    }
    return d;
  }
};


