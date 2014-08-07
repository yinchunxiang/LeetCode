#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
void print_vector(vector<char> input) {
    for (int i = 0; i < input[i]; ++i) {
        cout << input[i];
    }
    cout << endl;
}


void permute(vector<int>& used, vector<char> sub, vector<char>& result, int& count, int k) {
    if ( count >= k ) {
        return;
    }

    if (sub.size() >= used.size()) { 
        //print_vector(sub);
        count ++;
        if (count >= k) {
            result = sub;
            //cout << "result: " ;
            //print_vector(sub);
            
        }
        return;
    }

    for(int i = 0; i < used.size(); ++i) {
        if (!used[i]) {
            sub.push_back('1' + i);
            used[i] = 1;
            permute(used, sub, result, count, k);
            used[i] = 0;
            sub.pop_back();
        }

    }
}

string getPermutation(int n, int k) {
    vector<int> used(n, 0);
    vector<char> sub;
    vector<char> result;
    int count = 0;
    permute(used, sub, result, count, k); 
    string ret = "";
    for( int i = 0; i < result.size(); ++i) {
        ret += result[i];
    }
    return ret;
}
*/

int factorial(int n) {
    int result = 1;
    for( int i = 2; i<=n; ++i) {
        result *= i;
    }
    return result;
}

string kthPermutation(string& s, int n, int k) {
    string result(n, '0');
    int fac = factorial(n-1);
    for(int i = 0; i < n - 1; ++i) {
        int index = k/fac;
        result[i] = s[index];
        cout << "s[" << index << "] = " << s[index] << endl;
        s.erase(index, 1);
        k %= fac;
        fac /= (n-i-1);
        cout << "s = " << s << endl;
    }
    result[n-1] = s[0];
    return result;
}


string getPermutation(int n, int k) {
    /*
    if (n == 1) {
        return "1";
    }
    */
    string s(n,'0');
    for(int i = 0; i<n; ++i) {
        s[i] += i + 1;
    }

    return kthPermutation(s, n, k);
}

int main() {
    int n = 3, k = 2;
    cout << "n = " << n << " k = " << k << " " << endl;
    cout << getPermutation(n, k) << endl;
    cout << "=======================" << endl;

    n = 3, k = 4;
    cout << "n = " << n << " k = " << k << " " << endl;;
    cout << getPermutation(n, k) << endl;
    cout << "=======================" << endl;

    n = 9, k = 171669;
    cout << "n = " << n << " k = " << k << " " << endl;;
    cout << getPermutation(n, k) << endl;
    cout << "=======================" << endl;

    n = 1, k = 1;
    cout << "n = " << n << " k = " << k << " " << endl;;
    cout << getPermutation(n, k) << endl;
    cout << "=======================" << endl;

    n = 2, k = 1;
    cout << "n = " << n << " k = " << k << " " << endl;;
    cout << getPermutation(n, k) << endl;
    cout << "=======================" << endl;

}
