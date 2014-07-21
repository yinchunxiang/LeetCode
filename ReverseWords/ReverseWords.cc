#include <iostream>
#include <string> 

using namespace std;


string compress_space_and_reverse(string& s) {
    string ret = "";
    int is_pre_space = 1;
    int end = s.size() - 1;
    for (int i = end; i >=0; i--) {
        if (is_pre_space) {
            if (s[i] != ' ') {
                ret += s[i];
                is_pre_space = 0;
            }
        }
        else {
            if (s[i] == ' ') {
                is_pre_space = 1;
            }
            ret += s[i];
        }
    }

    int ret_size = ret.size();
    if (is_pre_space && ret_size >= 1) {
        return ret.erase(ret_size - 1);
    }
    return ret;
}

void reverseWords(string& s) {
    string ret = compress_space_and_reverse(s);
    cout << "after compress => [" << ret << "]" << endl;
    const int size = ret.size();
    int word_begin = 0;
    int word_end = 0;
    for (;word_begin < size; ++word_begin) {
        if(ret[word_begin] != ' '){
            word_end = word_begin; 
            while(word_end < size && ret[word_end] != ' ') {
                word_end ++;
            }
            int new_start = word_end;
            while(word_begin < (word_end - 1)) {
                int bak = ret[word_begin];
                ret[word_begin] = ret[word_end -1];
                ret[word_end - 1] = bak;
                word_begin ++;
                word_end --;
            }
            word_begin = new_start;
        }
    }
    s = ret;
}

int main(int argc, const char *argv[])
{
    string s = "the sky is blue " ;
    cout << "input => [" << s << "]" << endl; 
    reverseWords(s);
    cout << "output => [" << s << "]" << endl;
    return 0;
}

