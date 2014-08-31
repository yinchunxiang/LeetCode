#include <iostream>
#include <string> 


using namespace std;



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

int numDistinct(string S, string T) {
    int count  = 0;
    dfs(S, T, "", 0, count);
    return count;
}

int main(int argc, const char *argv[])
{
    cout << numDistinct("raa", "ra") << endl; 
    return 0;
}
