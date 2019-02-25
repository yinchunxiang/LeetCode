//
// Created by yinchunxiang on 2019-02-24.
//

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> dirs;
    auto j = path.end();
    for (auto i = path.begin(); i != path.end(); i = j) {
      ++i; // 这个很重要，千万别忘了
      j = std::find(i, path.end(), '/');
      auto dir = std::string(i, j);
      if (dir.empty()) continue;
      if (dir == ".") continue;
      if (dir == "..") {
        dirs.pop_back();
        continue;
      }
      dirs.push_back(dir);
    }
    if (dirs.empty()) return "/";
    std::string result;
    for (const auto& dir : dirs) {
      result += "/";
      result += dir;
    }
    return result;
  }
};


