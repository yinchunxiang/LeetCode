//
// Created by alexkkk on 2020/4/12.
//

#include <iostream>
#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  string longestDiverseStringV1(int a, int b, int c) {
    //using max heap
    priority_queue<pair<int,char>>pq;
    // 分别放入最大个数
    if(a) pq.push({a,'a'});
    if(b) pq.push({b,'b'});
    if(c) pq.push({c,'c'});
    string ans="";
    while(pq.size()>1){
      // 获得出现次数最多的2个字母
      pair<int,char>one = pq.top();pq.pop();
      pair<int,char>two = pq.top();pq.pop();
      int count = min(2, one.first);
      ans.append(min(2, one.first), one.second);
      one.first -= count;
      if(two.first >= 2 && two.first>=one.first){
        ans.append(2. two.second);
        two.first-=2;
      } else{
        ans+=two.second;
        two.first-=1;
      }
      if(one.first>0) pq.push(one);
      if(two.first>0) pq.push(two);
    }
    if(pq.empty()) return ans;
    if(pq.top().first>=2){
      ans+=pq.top().second;
      ans+=pq.top().second;
    }
    else{
      ans+=pq.top().second;
    }
    return ans;

  }

  string longestDiverseString(int a, int b, int c) {
    // 前面2个if保证 a >= b >= c
    if (a < b) {
      swap(aa_, bb_);
      return longestDiverseString(b, a, c);
    }
    if (b < c) {
      swap(bb_, cc_);
      return longestDiverseString(a, c, b);
    }
    if (b == 0) { // 此时 c == 0
      return string(min(2, a), aa);
    }
    // 每次都是最大的直接减掉2个
    auto use_a = min(2, a);
    // 看看下一轮最大还是不是a, 如果还是就需要加一个第二大的间隔一下, 如果不是则进行下一轮
    auto use_b = a - use_a >= b ? 1 : 0;
    return string(use_a, aa) +  string(use_b, bb) +
        longestDiverseString(a - use_a, b - use_b, c, aa, bb, cc);
  }

 private:
  char aa_ = 'a';
  char bb_ = 'b';
  char cc_ = 'c';

};

int main(int argc, char* argv[]) {


  return 0;
}

