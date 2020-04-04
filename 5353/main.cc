//
// Created by alexkkk on 2020/3/8.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    int max_on_pos = -1;
    int max_on_count = 0;
    int N = light.size();
    int result = 0;;
    vector<int> on_count_list(N, 0);
    for (int i = 0; i < N; ++i) {
      int pos = light[i] - 1;
      max_on_pos = max(max_on_pos, pos);
      max_on_count += 1;
      if (max_on_pos + 1 == max_on_count) {
        result += 1;
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  vector<int> light = {2,1,3,5,4};
  cout << s.numTimesAllBlue(light) << endl;
  return 0;
}

