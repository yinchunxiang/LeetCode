#include <iostream>
#include <string>
#include <tr1/unordered_set>
#include <vector> 
#include <utility>
#include <queue>


using namespace std;
using namespace tr1;

void printv(vector<string>& v){
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

int get_distance(const string& left, const string& right) {
    int ret = 0;
    for (int i = 0; i < left.size(); i++) {
        if (left[i] != right[i]) {
            ret ++; 
        }   
    }   
    return ret;
}

int ladderLength(string start, string end, unordered_set<string> &dict) {
    if(get_distance(start, end) <= 1){ 
        return 2;
    }   

    queue<string> q;
    queue<string> nq; 
    q.push(start);
    int level = 0;
    while(!q.empty()) {
        level ++; 
        while(!q.empty()) {
            string& curr = q.front();
            for (int i = 0; i < start.size(); i++) {
                for (char ch = 'a'; ch < 'z'; ch++) {
                    if (curr[i] == ch) {
                        continue;
                    }
                    string next = curr;
                    next.replace(i, 1, 1, ch);
                    if (next == end) {
                        return level + 1;
                    }   
                    if (dict.find(next) != dict.end()){
                        cout << "next: " << next << endl;
                        nq.push(next);
                        dict.erase(next);
                    }   

                }   
            }   
            q.pop();
        }
        swap(q, nq);
        cout << endl;
    }   

    return 0;
}

int main(int argc, const char *argv[])
{
    string a[] = {"hot","cog", "dot","dog","hit", "lot","log"};
    unordered_set<string> dict(a, a + 5);
    cout << ladderLength("hit", "cog", dict) << endl;


    string b[] = {"miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"};
    unordered_set<string> db(b, b+10);
    cout << ladderLength("kiss", "tusk", db) << endl;


    string c[] = {
        "ante","does","jive","achy",
        "kids","kits","cart","ache",
        "ands","ashe","acne","aunt",
        "aids","kite","ants","anne",
        "ashy"};
    unordered_set<string> dc(c, c+17);
    cout << ladderLength("kite", "ashy", dc) << endl;
    return 0;
}

