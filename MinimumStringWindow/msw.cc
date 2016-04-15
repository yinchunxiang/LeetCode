#include <iostream>
#include <unordered_map> 
#include <string> 

using namespace std;


typedef unordered_map<char, int> CharMap;

string minWindow(string S, string T) {
    int ns = S.size();
    int nt = T.size();
    if (0 == ns || 0 == nt) return "";
    if (ns < nt) return "";

    const int ASCII_MAX = 256;
    int appeared_count[ASCII_MAX] = {0};
    int expected_count[ASCII_MAX] = {0};

    for (int i = 0; i < nt; ++i) {
        ++ expected_count[T[i]];
    }

    int min_len = INT_MAX;
    int min_start = 0;
    int appeared = 0;
    int wnd_start = 0;

    for (int wnd_end = 0; wnd_end < ns; ++wnd_end) {
        if (expected_count[S[wnd_end]] > 0) {
            ++ appeared_count[S[wnd_end]];
            if (appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]]) {
                ++ appeared;
            }
        }

        if (appeared >= nt) {
            while (appeared_count[S[wnd_start]] > expected_count[S[wnd_start]] || !appeared_count[S[wnd_start]]) {
                appeared_count[S[wnd_start]] --;
                wnd_start ++;
            }
            int len = wnd_end - wnd_start + 1;
            if (min_len > len) {
                min_len = len;
                min_start = wnd_start;
            }
        }
    }
    if (min_len == INT_MAX) return "";
    return S.substr(min_start, min_len);
}

int main(int argc, const char *argv[])
{
    {
        string S = "ADOBECODEBANC";
        string T = "ABC";
        cout << minWindow(S, T) << endl; 
    }
    return 0;
}
