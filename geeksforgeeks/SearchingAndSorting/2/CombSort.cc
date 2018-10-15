//
// Created by yinchunxiang on 2018/5/27.
//

#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

using std::swap;

int GetNextGap(int gap) {
  gap = (gap * 10)/13;
  if (gap < 1) return 1;
  return gap;
}

void CombSort(vector<int>& a) {
  auto n = a.size();
  int gap = n;
  bool swapped = true;

  // swapped == false, means sort complete
  while (1 != gap || true == swapped) {
    gap = GetNextGap(gap);
    swapped = false;
    // compare all elements with current gap
    for (int i = 0; i < n - gap; i++) {
      if (a[i] > a[i + gap]) {
        swap(a[i], a[i + gap]);
        swapped = true;
      }
    }
  }
}

int main(int argc, const char *argv[]) {
  vector<int> a = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
  CombSort(a);
  cout << "after sort: " << endl;
  for (auto num : a) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
