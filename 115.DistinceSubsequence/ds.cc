#include <iostream>
#include <string> 


using namespace std;


// 思路： 得到所有长度和T一样的串， 在比较是不是和T相同
void dfs(string S, string T, string sub, int start, int& count){
    cout << "start:" << start << " " << sub << endl;
    if (start == S.size()) {
        return;
    }
    
    if (sub == T) {
        ++ count;
        return;
    }
    
    for( int i = start; i < S.size(); ++i){
        dfs(S, T, sub + S[i], start + 1, count);
        dfs(S, T, sub, start + 1, count);
    }
}

void dfs(const std::string& S, int index, const std::string& T, std::string sub, int& count) {
    if (sub.size() >= T.size()) {
        if (sub == T) count += 1;
        return;
    }
    if (index >= S.size()) return;
    dfs(S, index + 1, T, sub, count);
    sub.push_back(S[index]);
    dfs(S, index + 1, T, sub, count);
}

int numDistinct(string S, string T) {
    int count  = 0;
    //dfs(S, T, "", 0, count);
    dfs(S, 0, T, "", count);
    return count;
}

int main(int argc, const char *argv[])
{
    cout << numDistinct("raa", "ra") << endl; 
    return 0;
}
