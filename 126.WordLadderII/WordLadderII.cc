#include <iostream>
#include <string>
#include <vector>
#include <queue>
//#include <tr1/unordered_set>
#include <unordered_set>
//#include <tr1/unordered_map>
#include <unordered_map>
#include <list>

using namespace std;
//using namespace tr1;


void printv(vector<string>& v){
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " " ;
    }
    cout << endl;
}

void printvv(vector<vector<string> >& vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl << endl;
}

void print_map(unordered_map<string, vector<string> >& map) {
    unordered_map<string, vector<string> >::iterator it = map.begin();
    for(; it != map.end(); ++it){
        cout << it->first << " => ";
        printv(it->second);
    }
}

int is_disttance_ok(const string& left, const string& right) {
    int ret = 0;
    for (int i = 0; i < left.size(); ++i) {
        if (left[i] != right[i]) {
            ++ret;
            if ( ret > 1) {
                return 0;
            }
        }
    }
    return 1;
}


void dfs(const string& start, const string& end, vector<vector<string> >& result, vector<string> path, 
        unordered_map<string, vector<string> >& father) {
    if (end == start) {
        path.push_back(end);
        reverse(path.begin(), path.end());
        result.push_back(path);
        return;
    }

    unordered_map<string, vector<string> >::iterator it = father.find(end);
    if (it == father.end()) {
        return;
    }

    path.push_back(end);
    vector<string>& vs = it->second;
    for(int i = 0; i < vs.size(); ++i) {
        dfs(start, vs[i], result, path, father);
    }
    return;
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> > result;
    if (start == end) {
        return result;
    }

    unordered_set<string> curr_level;

    unordered_set<string> next_level;

    unordered_map<string, vector<string> > father;

    unordered_set<string> used;

    int found = 0;

    curr_level.insert(start);
    while(!curr_level.empty()) {
        for(unordered_set<string>::iterator it = curr_level.begin(); it != curr_level.end(); ++it){
            used.insert(*it);
        }
        for(unordered_set<string>::iterator it = curr_level.begin(); it != curr_level.end(); ++it){
            string curr = *it;
            for (int i = 0; i < curr.size(); i++) {
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    if (curr[i] == ch) {
                        continue;
                    }
                    string next = curr;
                    next[i] = ch;

                    if (next == end) {
                        next_level.insert(next);
                        father[next].push_back(curr);
                        found = 1;
                        break;
                    }

                    if (dict.find(next) != dict.end() && used.find(next) == used.end()) {
                        next_level.insert(next);
                        father[next].push_back(curr);
                    }
                }
            }
        }

        if (found) {
            break;
        }
        curr_level.clear();
        swap(curr_level, next_level);
    }

    print_map(father);

    vector<string> path;
    dfs(start, end, result, path, father);

    return result;

}

int main(int argc, const char *argv[])
{
    string a[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> dict(a, a + 5); 
    vector<vector<string> > vva = findLadders("hit", "cog", dict);
    printvv(vva);


    string b[] = {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
    unordered_set<string> db(b, b+10);
    vector<vector<string> > vvb =  findLadders("kiss", "tusk", db);
    printvv(vvb);


    string c[] = { 
        "ante","does","jive","achy",
        "kids","kits","cart","ache",
        "ands","ashe","acne","aunt",
        "aids","kite","ants","anne",
        "ashy"};
    unordered_set<string> dc(c, c+17);
    vector<vector<string> > vvc = findLadders("kite", "ashy", dc);
    printvv(vvc);

    return 0;  
}
