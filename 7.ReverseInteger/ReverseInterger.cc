#include <iostream>

using namespace std;
/*
int reverse(int x) {
    int ret = 0;
    int sign = 0;
    if (x < 0) {
        sign = 1;
        x = 0 - x;
    }
    for(; x; x/=10) {
        ret = ret*10 + x%10;
    }

    return sign == 1 ? 0 - ret : ret;

}
*/

int reverse(int x) {
    int r = 0;
    for (; x; x /= 10) {
        cout << x << "%10 => " << x%10 << endl;
        r = r * 10 + x % 10;
        cout << x << "/10 => " << x/10 << endl;
    }

    return r;
}


int main() {
    int x = 1;
    cout <<  x << " => " << reverse(x) << endl;
    x = -1;
    cout <<  x << " => " << reverse(x) << endl;
}
