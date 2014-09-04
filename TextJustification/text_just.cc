#include <iostream>
#include <vector>

using namespace std;

vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    vector<int> word_size_vec;
    int sum = 0;
    for (int i = 0; i < words; ++i) {
        sum += words[i].size();
        word_size_vec.push_back(sum);
    }

    int start = 0;
    int used = 0;
    for (int i = 0; i < word_size_vec; ++i) {
        if ( L < word_size_vec[i] - used ) {
            if ( i - start == 1) {
                string temp = words[i - 1] + string(L - word_size_vec[i - 1], ' ');
                result.push_back();
                start = i;
                used = word_size_vec[i - 1];
            }
            else {
                int pad_count = word_size_vec[i - 1] - L;
                int remainder = pad_count % i;
                int avg = pad_count / i;
                string temp;
                for (int j = start; j < i ; ++j){
                    if (j != start) {
                        if (remainder -- > 0) {
                            temp += string(avg + 1, ' ');
                        }
                        else {
                            temp += string(avg, ' ');
                        }
                    }
                    temp += words[j];
                }
            }
        }
    }
    return result;
}

void printv(vector<string>& v){ 
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << " " ; 
    }
    cout << endl << endl;;
}   


int main(int argc, const char *argv[])
{
    string arr[] = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<int> v(arr, arr + 7);
    vector<string> result = fullJustify(v) << endl;      
    printv(result);
    return 0;
}



