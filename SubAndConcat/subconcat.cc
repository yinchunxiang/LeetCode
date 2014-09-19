#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <string>


using namespace std;
using namespace tr1;


void printv(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    cout << endl;
}

vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> result;
    if (L.empty()) return result;
    int word_size = L[0].size();
    int word_count = L.size();
    //cout << "word_size: " << word_size << " word_count: " << word_count << endl;
    vector<string> sub;
    unordered_map<string, int> word_map;
    for (int i = 0; i < L.size(); ++i) {
        word_map[L[i]] += 1;
    }

    int n = S.size();
    for (int i = 0; i < n + 1 - word_count * word_size ; ++i) {
        unordered_map<string, int> has;
        int match_count = 0;
        for (int j = i; j <= i + word_size * (word_count - 1); j += word_size) {
            string temp  = S.substr(j, word_size);
            if (word_map.end() == word_map.find(temp)) {
                break;
            }
            ++has[temp];
            if (has[temp] > word_map[temp]) {
                break;
            }
            ++match_count;
        }
        if (match_count >= word_count) {
            result.push_back(i);
        }
    }
    return result;
}



int main(int argc, const char *argv[])
{
    {
        string S = "barfoothefoobarman";
        string p[] = {"foo", "bar"};
        vector<string> L(p, p + 2);
        vector<int> v = findSubstring(S, L);
        printv(v);
    }

    {
        string S = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
        string p[] = {"fooo","barr","wing","ding","wing"};
        vector<string> L(p, p + 5);
        vector<int> v = findSubstring(S, L);
        printv(v);
    }
    {
        string S = "a";
        string p[] = {"a"};
        vector<string> L(p, p + 1);
        vector<int> v = findSubstring(S, L);
        printv(v);
    }




    return 0;
}
