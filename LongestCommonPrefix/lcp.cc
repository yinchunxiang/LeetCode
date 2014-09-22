#include <vector>
#include <string>
#include <iostream>

using namespace std;

string get_common_prefix(const string& left, const string& right) {
    int ln = left.size();
    int rn = right.size();

    for (int i = 0; i < ln && i < rn; ++i) {
        if (left[i] != right[i]) {
            return left.substr(0, i);
        }
    }

    return left.substr(0, i);
}

string lcp(vector<string>& strs, int start, int end) {
    if (start == end) {
        return strs[start];
    }
    if (end == start + 1) {
        return get_common_prefix(strs[start], strs[end]);
    }

    int mid = (start + end) / 2;
    string left;
    string right;
    if (start <= mid ) {
        left = lcp(strs, start, mid);
    }
    if (mid + 1 <= end) {
        right = lcp(strs, mid + 1, end);
    }
    return get_common_prefix(left, right);
}

string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    return lcp(strs, 0, strs.size() - 1);
}
