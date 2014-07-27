class Solution {
public:
    string reverseString(string& s) {
        string ret = "";
        bool is_pre_space = true;
        for(int i = s.size() - 1; i >= 0; --i) {
            if (is_pre_space) {
                if (s[i] != ' ') {
                    ret += s[i];
                }
            }
            else {
                ret += s[i];
                if (s[i] == ' ') {
                    is_pre_space = true;
                }
            }
        }
        
        return ret;
    }
    void reverseWords(string &s) {
        string news = reverseString(s);
        int index = news.size();
        int word_begin = 0;
        int word_end = 0;
        while (word_begin < index) {
            while (news[word_begin] == ' ' && word_begin < index) {
                word_begin ++;
            }
            
            if (word_begin >= index) {
                break;
            }
            
            for (word_end = word_begin; news[word_end]!= ' ' && word_end < index; ++word_end) {
                
            }
            
            for (int begin = word_begin, end = word_end - 1; begin < end; begin ++, end --) {
                char temp = news[end];
                news[end] = news[begin];
                news[begin] = temp;
            }
            
            word_begin = word_end;
        }
        
    }
};
