//
// Created by alexkkk on 2019-05-26.
//

#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int n = grumpy.size();
    vector<int> diff(n - X + 1, 0);
    for (int i = 0; i < n; ++i) {
      if (grumpy[i] == 0) continue;
      for (int j = 0; j < X; ++j) {
        if (i - j < 0) break;
        diff[i - j] += customers[i];
      }
    }
    int max_diff = 0;
    for (auto v : diff) {
      max_diff = max(max_diff, v);
    }
    int result = max_diff;
    for (int i = 0; i < n; ++i) {
      if (1 == grumpy[i]) continue;
      result += customers[i];
    }
    return result;

  }
};


int main(int argc, char* argv[]) {
  vector<int> customers = {1,0,1,2,1,1,7,5};
  vector<int> grumpy = {0,1,0,1,0,1,0,1};
  int X = 3;
  Solution s;
  cout << s.maxSatisfied(customers, grumpy, X) << endl;
  return 0;
}
