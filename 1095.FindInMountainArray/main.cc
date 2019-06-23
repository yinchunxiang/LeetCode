//
// Created by alexkkk on 2019-06-23.
//

class Solution {
public:
  int find(MountainArray& m, int start, int end) {
    while (start < end) {
      // 1个元素就判断不出来了
      //if (start + 1 == end) return -1;
      int mid = start + (end - start) / 2;
      cout << "--> find mid: " << mid << endl;
      if (m.get(mid) > m.get(mid - 1) && m.get(mid) > m.get(mid + 1)) {
        return mid;
      }
      // 顶峰在右边
      if (m.get(mid - 1) < m.get(mid) && m.get(mid) < m.get(mid + 1)) {
        cout << "-> to right" << endl;
        start = mid + 1;
      } else if (m.get(mid - 1) > m.get(mid) && m.get(mid) > m.get(mid + 1)) {
        cout << "-> to left" << endl;
        end = mid;
      } else {
        cout << "-> not good" << endl;
        return -1;
      }
    }
    return -1;
  }

  int findLeft(MountainArray& m, int left, int right, int target) {
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (target == m.get(mid)) return mid;
      if (target < m.get(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }

  int findRight(MountainArray& m, int left, int right, int target) {
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (target == m.get(mid)) return mid;
      if (target > m.get(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }

  int findInMountainArray(int target, MountainArray &mountainArr) {
    if (mountainArr.length() < 3) return -1;
    // 要知道顶峰肯定不是0 和 N - 1, 所以限定查找范围是 [1, N - 1)
    int mid = find(mountainArr, 1, mountainArr.length() - 1);
    cout << "-> mid: " << mid << endl;
    if (-1 == mid) return -1;
    if (target == mountainArr.get(mid)) return mid;
    auto l = findLeft(mountainArr, 0, mid, target);
    if (-1 != l) return l;
    return findRight(mountainArr, mid + 1, mountainArr.length(), target);
  }
};

