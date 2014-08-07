#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tr1/unordered_set>

using namespace std;
using namespace tr1;

void printvv(vector<vector<string> >& vv) {
    for (int i = 0; i < vv.size(); i++) {
        for (int j = 0; j < vv[i].size(); j++) {
            cout << vv[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl << endl;
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

/*
vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> > result;
    vector<string> sub;
    sub.push_back(start);
    if (is_disttance_ok(start, end)) {
        sub.push_back(end);
        result.push_back(sub);
        return result;
    }

    queue<string> q;
    q.push(start);
    queue<string> nq;

    queue< vector<string> > sub_path_queue;
    sub_path_queue.push(sub);

    queue< unordered_set<string> > dq;
    dq.push(dict);

    int level = 0;
    int found = 0;

    while(!q.empty()) {
        ++level;
        while(!q.empty()){
            string& curr = q.front();
            vector<string>& sub_path = sub_path_queue.front();
            unordered_set<string>& sub_dict = dq.front();
            for (int i = 0; i < curr.size(); i++) {
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    if (curr[i] == ch) {
                        continue;
                    }
                    string next = curr;
                    next.replace(i, 1, 1, ch);

                    if (next == end) {
                        vector<string> new_path = sub_path;
                        new_path.push_back(end);
                        result.push_back(new_path);
                        found = 1;
                        continue;
                    }

                    if (sub_dict.find(next) != sub_dict.end()) {
                        nq.push(next);

                        vector<string> new_path = sub_path;
                        new_path.push_back(next);
                        sub_path_queue.push(new_path);


                        unordered_set<string> new_dict = sub_dict;
                        new_dict.erase(next);
                        dq.push(new_dict);
                    }
                }
            }

            q.pop();
            sub_path_queue.pop();
            dq.pop();
        }

        if (found) {
            break;
        }

        swap(q, nq);
        
    }

    return result;

}
*/

void dfs(const string& start, const string& end, unordered_set<string> dict,vector<string> sub_path, 
        vector< vector<string> >& result, int& min) {
    if (sub_path.size() > min) {
        return;
    }
    for(int i = 0; i < start.size(); ++i){
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (start[i] == ch) {
                continue;
            }

            string next = start;
            next.replace(i, 1, 1, ch);
            if (next == end) {
                sub_path.push_back(next);
                int n = sub_path.size();
                if (n < min) {
                    min = n;
                    result.clear();
                    result.push_back(sub_path);
                }
                else if (n == min) {
                    result.push_back(sub_path);
                }

                continue;
            }

            if (dict.find(next) != dict.end()){
                sub_path.push_back(next);
                dict.erase(next);
                dfs(next, end, dict, sub_path, result, min);
                sub_path.pop_back();
                dict.insert(next);
            }

        }
    }
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> > result;
    vector<string> sub_path;
    int min = dict.size() + 3;
    dfs(start, end, dict, sub_path, result, min);
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
