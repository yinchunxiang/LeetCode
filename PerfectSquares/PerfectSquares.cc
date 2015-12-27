#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int numSquares(int n) {
    if (1 == n) return 1;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        v[i] = i;
        for (int j = 1; i - j*j >= 0; ++j) {
            if (v[i - j*j] + 1 < v[i]) {
                v[i] = v[i - j*j] + 1;
            }
        }
    }
    return v[n];
}

int main(int argc, const char *argv[])
{
    cout << numSquares(12) << endl;
    cout << numSquares(4) << endl;
    return 0;
}
