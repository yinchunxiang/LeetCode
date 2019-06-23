//
// Created by alexkkk on 2019-06-23.
//

/*
 * You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips.



Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
Example 3:

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true
Example 4:

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true
 */

class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    auto comp = [](const vector<int>& l, const vector<int>& r) {
      return l[1] < r[1];
    };
    auto cmp = [](const vector<int>& l, const vector<int>& r) {
      return l[2] > r[2];
    };
    // 这个保证到达有序，先到达的在上面
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> p(cmp);
    // 这个保证出发地点有序, 从近到远
    sort(begin(trips), end(trips), comp);
    for (int i = 0; i < trips.size(); ++i) {
      const auto& trip = trips[i];
      // 有没有要下的
      while (!p.empty()) {
        auto& t = p.top();
        cout << "trip: (" << trip[0] << "," << trip[1] << "," << trip[2] << ")" << endl;
        cout << "(" << t[0] << "," << t[1] << "," << t[2] << ")" << endl;
        if (trip[1] >= t[2]) {
          capacity += t[0];
          p.pop();
          continue;
        }
        break;
      }

      // 再处理要上的
      if (capacity < trip[0]) {
        return false;
      }
      capacity -= trip[0];
      p.push(trip);
    }
    return true;
  }
};

