//
// Created by alexkkk on 2020/2/4.
//

string minWindow(string s, string t) {
  /// 1. 构造目标串的map
  // 记录 t 里面每个字符串出现的次数
  vector<int> map(128,0);
  for(auto c: t) map[c]++;
  /// 2. 检查目标子串是否合法的计数器
  int counter=t.size();
  // 滑动窗口的开始位置
  int begin = 0;
  // 滑动窗口的结束位置
  int end = 0;
  int N = s.size();
  int d = N + 1;
  // 用来记录最优结果的开始位置
  int head = N;
  while(end < N){
    /// 3. end一直往前走, 修改计数器 counter
    // end 一直走
    if(map[s[end++]]-- > 0) counter--; //in t
    // 滑动窗口包含 t 里面所有字母的时候, 开始移动start，直到不合法

    /// 4. 在满足限制条件的情况下，start往前走
    while(0 == counter){ //valid
      auto size = end - begin;
      if (size < d) {
        d = size;
        head = begin;
      }
      if(map[s[begin++]]++==0) counter++;  //make it invalid
    }
  }
  return s.substr(head, d);
}

