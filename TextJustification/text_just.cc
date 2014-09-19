#include <iostream>
#include <vector>
#include <string>


using namespace std;

void printv(vector<string>& v){ 
    for (int j = 0; j < v.size(); j++) {
        cout << "[" <<  v[j] << "] " << endl; 
    }
    cout << endl;
}   

void printvi(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    cout << endl;
}


vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;

    int start = 0;
    int curr_size = 0;
    int N = words.size() ;
    for (int i = 0; i < N; ++i) {
        curr_size += words[i].size();
        cout << "i: " << i << "  curr_size: " << curr_size << " start: " << start << endl;
        int min_pad_count = i - start;
        cout << "min_pad_count: " << min_pad_count << endl;
        if (L >= curr_size + min_pad_count && (N - 1 == i || L < curr_size + words[i + 1].size() + min_pad_count + 1)) {
            int delimiter = i - start;
            string temp;
            int pad_count = L - curr_size;
            int remainder = delimiter == 0 ? 0 : pad_count % delimiter;
            if (i == N - 1) {
                remainder = 0;
            }
            int avg = delimiter == 0 ? pad_count :pad_count / delimiter;
            if (i == N - 1) {
                avg = 1;
            }
            cout << "remainder: " << remainder << " avg: " << avg << endl;
            for (int j = start; j <= i ; ++j){
                temp += words[j];
                if (j == i) { // if it is the last and not the first
                    continue;
                }

                if (remainder -- > 0) {
                    temp += string(avg + 1, ' ');
                }
                else {
                    temp += string(avg, ' ');
                }

            }
            
            if (temp.size() < L) {
                temp.append(L - temp.size(), ' ');
            }

            result.push_back(temp);
            start = i + 1;
            curr_size = 0;
        }
    }
    return result;
}



int main(int argc, const char *argv[])
{
    string arr[] = {"Here","is","an","example","of","text","justification."};
    vector<string> v(arr, arr + 7);
    vector<string> result = fullJustify(v, 14);
    printv(result);

    string b[] = {"What","must","be","shall","be."};
    vector<string> vb(b, b + 5);
    result = fullJustify(vb, 12);
    printv(result);

    string c[] = {""};
    vector<string> vc(c, c + 1);
    result = fullJustify(vc, 2);
    printv(result);

    string d[] = {""};
    vector<string> vd(d, d + 1);
    result = fullJustify(vd, 0);
    printv(result);

    string e[] = {"My","momma","always","said,","\"Life","was","like","a","box","of","chocolates.","You","never","know","what","you're","gonna","get."};
    vector<string> ve(e, e + 18);
    result = fullJustify(ve, 20);
    printv(result);
    return 0;
}



