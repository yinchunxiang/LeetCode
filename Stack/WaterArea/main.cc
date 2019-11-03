#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  stack<int> s1;

  stack<pair<int, int>> s2;
  int sum = 0;
  string input = R"(\\\//)";
  for (int i = 0; i < input.size(); ++i) {
    char ch = input[i];
    if (ch == '\\') {
      s1.push(i);
      continue;
    }
    if (ch == '/' && !s1.empty()) {
      int j = s1.top();
      s1.pop();
      sum += i - j;
      int a = i - j;
      while (!s2.empty() && s2.top().first > j) {
        a += s2.top().second;
        s2.pop();
      }
      s2.push(make_pair(j, a));
    }
  }
  vector<int> ans;
  while (!s2.empty()) {
    ans.push_back(s2.top().second);
    s2.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << sum << endl;
  cout << ans.size();
  for (int i = 0; i < ans.size(); ++i) {
    cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}