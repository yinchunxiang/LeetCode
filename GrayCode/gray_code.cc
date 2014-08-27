#include <iostream>
#include <vector>

using namespace std;



vector<int> grayCode(int n) {

    vector<int> curr_level;
    curr_level.push_back(0);
    if (n == 0) {
        return curr_level;
    }
    vector<int> next_level;

    int level = 0;
    while(level < n) {
        for (int i = 0; i < curr_level.size(); ++i) {
            int temp = curr_level[i];
            next_level.push_back(temp);
            //cout << "temp: " << temp << endl;
            //cout << "v[" << i << "]:" << curr_level[i] <<endl;
        }

        for (int i = curr_level.size() - 1; i >= 0; --i) {
            int temp = (1 << level) | curr_level[i];
            next_level.push_back(temp);
            //cout << "temp: " << temp << endl;
            //cout << "v[" << i << "]:" << curr_level[i] <<endl;
        }
        curr_level.clear();
        curr_level.swap(next_level);
        level ++;
    }
    return curr_level;
}

int main(int argc, const char *argv[])
{
    vector<int> result;
    result = grayCode(2);
    for (int i = 0; i < result.size(); ++i){
        cout << result[i] << endl;
    }

    result = grayCode(3);
    for (int i = 0; i < result.size(); ++i){
        cout << result[i] << endl;
    }
    return 0;
}


