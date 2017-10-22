#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;


typedef std::tr1::unordered_map<int, bool> Map;

void print_map(Map& map){
    for (Map::iterator it = map.begin(); it != map.end(); ++it) {
        cout << "used[" << it->first << "]:" << it->second << endl;
    }
    cout << endl << endl;
}


int longestConsecutive(vector<int> &num) {
    // 当输入的数组为空的时候，返回0
    int longest = 0;
    Map used;
    for (int i = 0; i < num.size(); i++) {
        used[num[i]] = false;
    }


    for (int i = 0; i < num.size(); i++) {
        if (used[num[i]]) {
            continue;
        }

        // 先要把自己设置为true
        used[num[i]] = true;
        int length = 1;
        
        for(int prev = num[i] - 1; used.find(prev) != used.end(); --prev) {
            used[prev] = true;
            ++length;
        }

        for (int next = num[i] + 1; used.find(next) != used.end(); ++next) {
            used[next] = true;
            ++length;
        }

        if (length > longest) {
            longest = length;
        }

    }

    return longest;
}



int main(int argc, const char *argv[])
{
    int input[] = {100, 4, 200, 1, 3, 2} ;
    vector<int> vi(input, input + 6);
    cout << longestConsecutive(vi) << endl;
    return 0;
}
