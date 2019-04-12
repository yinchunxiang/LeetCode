//
// Created by alexkkk on 2019-04-07.
//

/*
5019. Video Stitching
User Accepted: 983
User Tried: 1202
Total Accepted: 1049
Total Submissions: 2431
Difficulty: Medium
    You are given a series of video clips from a sporting event that lasted T seconds.  These video clips can be overlapping with each other and have varied lengths.

Each video clip clips[i] is an interval: it starts at time clips[i][0] and ends at time clips[i][1].  We can cut these clips into segments freely: for example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].

Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event ([0, T]).  If the task is impossible, return -1.



Example 1:

Input: clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
Output: 3
Explanation:
We take the clips [0,2], [8,10], [1,9]; a total of 3 clips.
Then, we can reconstruct the sporting event as follows:
We cut [1,9] into segments [1,2] + [2,8] + [8,9].
Now we have segments [0,2] + [2,8] + [8,10] which cover the sporting event [0, 10].
Example 2:

Input: clips = [[0,1],[1,2]], T = 5
Output: -1
Explanation:
We can't cover [0,5] with only [0,1] and [0,2].
Example 3:

Input: clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
Output: 3
Explanation:
We can take clips [0,4], [4,7], and [6,9].
Example 4:

Input: clips = [[0,4],[2,8]], T = 5
Output: 2
Explanation:
Notice you can have extra video after the event ends.
*/

// 感觉有点像跳台阶那个， 最少多少步能跳到顶
// 每个时间段，代表的是从某个台阶能跳的最远距离
// 从0开始最远跳多远， [0, 1], [0, 2], [0, 4], 最远跳到4
// 下面就变成，从 1/2/3/4开始跳，最远跳到多少， 假设最远是10，
// 则接下来变成从 5/6/7/8/9/10开始跳最远到多少
// 感觉本质变成是bfs， 最短距离、最少步骤 => bfs, 以后可以尽量往这个方面靠

class Solution {
public:
  int videoStitching(vector <vector<int>> &clips, int T) {
    if (0 == T && clips.empty()) return 0;
    if (clips.empty()) return -1;
    sort(clips.begin(), clips.end());
    vector<vector<int>> result;
    int count = 0;
    int end = 0;
    for (int i = 0; i < clips.size(); ++i) {
      if (clips[i][0] > end) return -1;
      int new_end = end;
      while(i < clips.size() && clips[i][0] <= end) {
        new_end = max(new_end, clips[i][1]);
        i+= 1;
      }
      count += 1;
      end = new_end;
      if (end >= T) break;
      i -= 1;
    }
    if (end < T) return -1;
    return count;



  }
};
