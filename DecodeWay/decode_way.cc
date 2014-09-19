#include <iostream>
#include <string>
#include <vector>



using namespace std;



void decode(const string& s, int start, int& sum) {
    const int n = s.size();
    if (n == start){
        sum += 1;
        return;
    }

    int number = 0;
    for(int i = start; i < start + 2 && i < n; ++i){
        number = 10 * number + s[i] - '0';
        if (number <= 26) {
            decode(s, i + 1, sum);
        }
    }

    return;
}

int numDecodings1(string s) {
    int sum = 0;
    decode(s, 0, sum);
    return sum;
}

/*
   int numDecodings(string s) {
   if (s.empty()) return 0;
   int n = s.size();
   vector<int> f(n, 1);

   int prev = s[0] - '0';
   for( int i = 1; i < n + 1; ++i) {
   int curr = s[i] - '0';
   int number = 10 * prev + curr;
   prev = curr;
   int r1 = 0;
   int r2 = 0;
   if (curr > 0) {
   r1 = f[i];
   }

   if (number <= 26 && number >= 10) {
   r2 =  f[i - 1];
   }

   f[i + 1]  = r1 + r2;

   }
   return f[n];
   }
   */

int numDecodings(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    vector<int> f(n + 1, 0);
    f[0] = 1;
    int prev = s[0] - '0';
    if (prev >= 1 && prev <= 9) {
        f[1] = 1;
    }
    for( int i = 1; i < n + 1; ++i) {
        int curr = s[i] - '0';
        int number = 10 * prev + curr;
        prev = curr;
        int r1 = 0;
        int r2 = 0;
        if (curr > 0) {
            r1 = f[i];
        }   

        if (number <= 26 && number >= 10) {
            r2 =  f[i - 1]; 
        }   

        f[i + 1]  = r1 + r2; 

    }   
    return f[n];
}


int main(int argc, const char *argv[])
{
    string input = "10";
    cout << numDecodings(input) << endl;

    input = "123";
    cout << numDecodings(input) << endl;

    return 0;
}
