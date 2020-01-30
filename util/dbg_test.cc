//
// Created by alexkkk on 2019/12/28.
//

#include "dbg.h"
#include <string>
#include <map>

//std::ostream& operator<<(std::ostream& out, const std::pair<int, int>& v) {
//  out << "…";
//  return out;
//}

template<typename First, typename Second>
std::ostream& operator<<(std::ostream& out,  const std::pair<First, Second>& v) {
  out << "(" << v.first << "," << v.second << ")";
  return out;
}


int main(int argc, char* argv[]) {
  std::vector<int> v = {1, 2};
  dbg(v);

//  std::map<std::string, int> m = {{"a", 1}, {"b", 2}};
//  dbg(m);

  std::pair<int, int> p(1, 2);
  dbg(p);


  return 0;
}

