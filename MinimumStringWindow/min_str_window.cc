#include <iostream>
#include <tr1/unordered_map> 
#include <string>

using namespace std;
using namespace tr1;

string minWindow(string S, string T) {
    if (T.empty()){
        return "";
    }
    string ret;
    int min_len = S.size() + 1;
    int unique_match = 0;
    int window_size = 0;
    unordered_map<char, int> char_map;
    for (int i = 0; i < T.size(); ++i) {
        char_map[T[i]] = 0;
    }
    int start = 0;;
    for (int i = 0; i < S.size(); ++i) {
        unordered_map<char, int>::iterator it = char_map.find(S[i]);
        if (it == char_map.end()) {
            continue;
        }
        if (0 == it->second ++) {
            unique_match ++;
        }
        if (unique_match >= T.size()) {
            for (; start <= i ; ++ start){
		unordered_map<char, int>::iterator it = char_map.find(S[start]);
		if (char_map.end() == it){
		    continue;
		}
                if (it->second <= 1){
                    break;
                }
                else {
                    it->second --;
                }
            }
            int curr_window_size = i - start + 1;
            if (curr_window_size < min_len){
                min_len = curr_window_size;
                ret = string(S, start, curr_window_size);
                cout << "start: " << start << endl;
                cout << "i: " << i << endl;
                cout << "ret: " << endl;
            }
        }
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << minWindow(S, T) << endl;
    return 0;
}
