#include <iostream>
#include <string>
#include <vector>


using namespace std;


int longestValidParentheses(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<int> f(n, 0);
    int max_size = 0;
    for (int i = n - 2; i >= 0; --i) {
        if ('(' == s[i]) {
            int match_index = i + f[i + 1] + 1;
            if (s[match_index] == ')') {
                f[i] = f[i + 1] + 2;
            }
            if (match_index < n - 1) {
                f[i] += f[match_index + 1];
            }

            if (f[i] > max_size) {
                max_size = f[i];
            }
        }
    }
    return max_size;
}

void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int long2(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<int> f(n, 0);
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; ++i) {
        if ('(' == s[i]) {
            left ++;
        }
        if (')' == s[i]) {
            right ++;
            if (left >= right) {
                f[i] = 1;
            }
            else {
                left = 0; 
                right = 0;
            }
        }
    }
    left = 0;
    right = 0;
    for (int i = n - 1; i >= 0; --i) {
        if ('(' == s[i]) {
            left ++;
            if (left <= right) {
                f[i] = 1;
            }
            else {
                left = 0; 
                right = 0;
            }
        }
        if (')' == s[i]) {
            right ++;
        }
    }

    printv(f); 

    int max_count = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i] == 1) {
            count ++;
        }
        else {
            if (count > max_count) {
                max_count = count;
            }
            count = 0;
        }
    }
    return max_count;
}


int main(int argc, const char *argv[])
{
    string s= "()(()";
    cout << longestValidParentheses(s) << endl;
    cout << long2(s) << endl;
    return 0;
}

