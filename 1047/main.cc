#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
//    string remove_dup(string str) {
//        if (str.size() <= 1) return str;
//        str.push_back('$');
//        string result;
//        int next = 0;
//        int count = 0;
//        for (int i = 0; i < str.size(); ++i) {
//            if (0 == i) {
//                count = 1;
//                continue;
//            }
//            if (str[i] == str[i - 1]) {
//                count += 1;
//            } else {
//                if (1 == count) {
//                    result.push_back(str[i - count]);
//                }
//                count = 1;
//            }
//        }
//        return result;
//    }

  string remove_dup(string str) {
    if (str.size() <= 1) return str;
    str.push_back('$');
    string result;
    int start = 0;
    int end = start;
    for (int end = 0; end < str.size(); ) {
      if (start == end) {
        end += 1;
        continue;
      }
      if (str[start] == str[end]) {
        start += 2;
        end = start;
        continue;
      }
      result += str[start++];
    }

    return result;
  }
    string removeDuplicates(string S) {
        while (S.size() > 1) {
            auto result = remove_dup(S);
            cout << "input: " << S << endl;
            cout << "output: " << result << endl;
            cout << "--------------------------------" << endl;
            if (result.size() == S.size()) {
                return S;
            }
            result.swap(S);
        }
        return S;
    }
};

int main(int argc, const char *argv[]) {
  Solution s;
  cout << s.removeDuplicates("abbaca") << endl;
  cout << s.removeDuplicates("aaaaaaaaa") << endl;
  return 0;
}

