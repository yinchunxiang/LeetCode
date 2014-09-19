#include <string>
#include <iostream> 

using namespace std;



string addBinary(string a, string b) {
    string ret;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    for (; i >= 0 && j >= 0; --i, --j) {
        int sum = a[i] - '0' + b[j] - '0' + carry;
        carry = sum / 2;
        int digit = sum % 2;
        cout << "1111 carry: " << carry << " digit: " << digit << endl;
        ret.insert(0, 1, digit + '0');
    }

    for (; i >= 0; --i) {
        if (0 == carry) {
            ret.insert(0, a.substr(0, i + 1));
            break;
        }
        else {
            
            int sum = a[i] - '0' + carry;
            cout << "i: " << i << "sum: " << sum << endl;
            carry = sum / 2;
            int digit = sum % 2;
            ret.insert(0, 1, digit + '0');
            cout << "2222 carry: " << carry << " digit: " << digit << endl;
        }

    }

    for (; j >= 0; --j) {
        if (0 == carry) {
            ret.insert(0, b.substr(0, j + 1));
            break;
        }
        else {
            int sum = b[j] - '0' + carry;
            carry = sum / 2;
            int digit = sum % 2;
            ret.insert(0, 1, digit + '0');
            cout << "333 carry: " << carry << " digit: " << digit << endl;
        }
    }

    if (carry == 1) {
        ret.insert(0, 1, '1');
    }

    return ret;
}

int main(int argc, const char *argv[])
{
    string a = "11";
    string b = "1";
    cout << addBinary(a, b) << endl;
    return 0;
}
