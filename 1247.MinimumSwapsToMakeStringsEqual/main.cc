//
// Created by alexkkk on 2019/11/3.
//

#include <dbg-macro/dbg.h>

class Solution {
 public:
  int minimumSwap(string s1, string s2) {
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    for (int i = 0; i < s1.size(); ++i) {
      char c1 = s1[i];
      char c2 = s2[i];
      if (c1 == c2) continue;
      if (c1 == 'x') {
        x1 += 1;
      } else {
        y1 += 1;
      }
      if (c2 == 'x') {
        x2 += 1;
      } else {
        y2 += 1;
      }
    }

    if ((x1 + x2) % 2 != 0 || (y1 + y2) % 2 != 0) {
      return -1;
    }

    int swaps = x1 / 2 + y1 / 2 + (x1 % 2) * 2;
    // Cases to do 1 swap:
    // "xx" => x1 / 2 => how many pairs of 'x' we have ?
    // "yy" => y1 / 2 => how many pairs of 'y' we have ?
    //
    // Cases to do 2 swaps:
    // "xy" or "yx" =>  x1 % 2
    return swaps;
  }
};