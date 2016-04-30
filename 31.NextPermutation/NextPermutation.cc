#include <iostream>
#include <vector>

using namespace std;


int find_peak(const vector<int>& num) {
    int ret = 0;
    for(int i = num.size() - 1, j = i -1; i>=0 && j>=0; i--,j--) {
        if (num[j] < num[i]) {
            ret = i;
            break;
        }
    }
    return ret;
}
void nextPermutation(vector<int> &num) {
    int vec_size = num.size();
    if (vec_size <= 1) {
        return;
    }
    int peak = find_peak(num);
    cout << "peak index: " << peak << endl;
    if (0 >= peak) {
        sort(num.begin(), num.end());
        return;
    }

    if (peak == vec_size - 1) {
        swap(num[peak - 1], num[peak]);
        return;
    }


    for(int i = vec_size - 1; i >= peak; i--) {
        if (num[i] > num[peak - 1]){
            swap(num[peak - 1], num[i]);        
            break;
        }
    }

    sort(num.begin() + peak, num.end());
}

void print_vector(const vector<int>& vec) {
    vector<int>::const_iterator it = vec.begin();
    for(; it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {1,2,3};
    vector<int> va(a, a + 3);
    cout << "input: " ; 
    print_vector(va);
    nextPermutation(va);
    print_vector(va);
    cout << "======================" << endl;

    int b[] = {1,3,2} ;
    cout << "input: " ; 
    vector<int> vb(b, b + 3);
    print_vector(vb);
    nextPermutation(vb);
    print_vector(vb);
    return 0;
}
