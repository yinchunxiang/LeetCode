//
// Created by alexkkk on 2020/1/27.
//

#include <vector>
#include <deque>
#include "../util/dbg.h"

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
  int n = T.size();
  vector<int> result(n, 0);
  deque<int> d;
  for (int i = 0; i < n; ++i)  {
    dbg(d);
    while (!d.empty() && T[d.back()] < T[i]) {
      result[d.back()] = i - d.back();
      d.pop_back();
    }
    d.push_back(i);
  }
  return result;
}

int main(int argc, char* argv[]) {
  vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
  dbg(dailyTemperatures(input));
  return 0;
}