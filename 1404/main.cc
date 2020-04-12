//
// Created by alexkkk on 2020/4/6.
//

#include <string>
#include <iostream>
#include "../util/dbg.h"

using namespace std;


class Solution {
 public:
  int numSteps(string s) {
    dbg(s);
    int N = s.size();
    int count = 0;
    int carry = 0;
    for (int i = N - 1; i > 0; --i) {
      cout << "--> i:" << i << " count:" << count << " carry:" << carry << endl;
      int sum = carry + (s[i] - '0');
      // switch这块的逻辑可以优化，见下面
      switch (sum) {
        case 0:
          count += 1;
          break;
        case 1:
          carry = 1;
          count += 2;
          break;
        case 2:
          carry = 1;
          count += 1;
          break;
        default:
            break;
      }
    }
    return count + carry;
  }

  int numSteps(string s) {
    dbg(s);
    int N = s.size();
    int count = 0;
    int carry = 0;
    for (int i = N - 1; i > 0; --i) {
      cout << "--> i:" << i << " count:" << count << " carry:" << carry << endl;
      count += 1;
      int sum = carry + (s[i] - '0');
      if (1 == sum ) {
        count += 1;
        carry = 1;
      }
    }
    return count + carry;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  cout << s.numSteps("1101") << endl;

  return 0;
}

