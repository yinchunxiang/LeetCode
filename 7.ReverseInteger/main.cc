//
// Created by yinchunxiang on 2019-03-02.
//

/*
 * 这个是比较清晰好理解的版本
 */
class Solution {
 public:
  int reverse(int x) {
    if (INT_MIN == x) return 0;
    if (0 == x) return 0;
    bool positive = x > 0;
    if (!positive) {
      x = -x;
    }
    int r = 0;
    for (; x ; x /= 10) {
      if (r > INT_MAX/10 || r * 10 > INT_MAX - x % 10) {
        return 0;
      }
      r = r * 10 + x % 10;
    }
    return positive ? r : -r;
  }
};
