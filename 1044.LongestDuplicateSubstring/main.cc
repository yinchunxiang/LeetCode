//
// Created by yinchunxiang on 2019-05-15.
//
/**
Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)



Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""


Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
 */

struct suffix {
  int index;
  int rank[2];
};
bool cmp(struct suffix a, struct suffix b) {
  if (a.rank[0] < b.rank[0]) return true;
  if (a.rank[0] > b.rank[0]) return false;
  return a.rank[1] < b.rank[1];
}

vector<int> build_suffix_array(const string& txt) {
  vector<suffix> suffixes(n);
  for (int i = 0; i < txt.size(); ++i) {
    suffixes[i].index = i;
    suffixes[i].rank[0] = txt[i] - 'a';
    suffixes[i].rank[1] = (i + 1 < txt.size() ? txt[i + 1] - 'a' : -1); // 表示最后一个字符顺序是最小的？
  }
  // 其实是根据suffix的前2个字符，对suffix进行排序
  sort(suffixes.begin(), suffixes.end(), cmp);
  vector<int> ind(txt.size());
  for (int k = 4; k < 2 * txt.size(); k *= 2) {
    int rank = 0;
    int prev_rank = suffixes[0].rank[0];
    suffixes[0].rank[0] = rank;
    ind[suffixes[0].index] = 0;

    for (int i = 1; i < txt.size(); ++i) {
      if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
        prev_rank = suffixes[i].rank[0];
        suffixes[i].rank[0] = rank;
      } else {
        prev_rank = suffixes[i].rank[0];
        suffixes[i].rank[0] = ++rank;
      }
      ind[suffixes[i].index] = i;
    }

    for (int i = 0; i < txt.size(); ++i) {
      int nextindex = suffixes[i].index + k/2;
      suffixes[i].rank[1] = nextindex < txt.size() ? suffixes[ind[nextindex]].rank[0] : -1;
    }
    sort(suffixes.begin(), suffixes.end(), cmp);
  }

}
