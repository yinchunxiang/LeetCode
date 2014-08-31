#include <iostream>
#include <tr1/unordered_map> 

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
        if (!char_map(S[i])) {
            unique_match ++;
        }
        char_map[S[i]] ++;
        if (unique_match >= T.size()) {
            for (; start <= i ; ++ start){
                if (char_map[S[start]] > 1){
                    char_map[S[start]] --;
                }
                else {
                    break;
                }
            }
            int curr_window_size = i - start + 1;
            if (curr_window_size < min_len){
                min_len = curr_window_size;
                ret = string(start, curr_window_size);
            }
        }
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    S = "ADOBECODEBANC";
    T = "ABC";
    cout << minWindow(S, T) << endl;
    return 0;
}
