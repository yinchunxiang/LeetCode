#include "./dbg.h"

#include <map>
#include <unordered_map>

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& v) {
  out << "<" << v.first << "," << v.second << ">";
  return out;
}


//template<typename T1, typename T2>
//std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& v) {
//  out << "{" << v.first << "," << v.second << "}";
//  return out;
//}

//template<typename T1, typename T2>
//std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& v) {
//  out << "{" << v.first << "," << v.second << "}";
//  return out;
//}
int main() {
    std::unordered_map<int, int> input = {
        {1, 2},
        {3, 4}
    };
    dbg(input);

    std::unordered_map<char, int> char_int_map = {
        {'a', 1 },
        {'b', 2}
    };
    dbg(char_int_map);

    dbg(std::pair<int, bool>{3, false});
    dbg(std::pair<bool, int>{true, 47});

}
