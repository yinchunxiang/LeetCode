#include <iostream>

using namespace std;

int atoi(const char *str) {
        long ret = 0;
        int negative = 0;
        while(*str != '\0') {
            if (isdigit(*str)) {
                ret = ret*10 + *str - '0';
                str++;
                break;
            }
            
            if (*str == '+') {
                str++;
                break;
            } 
            
            if (*str == '-') {
                negative = 1;
                str++;
                break;
            }
            str++;
        }
        while(*str != '\0' && isdigit(*str)) {
            int number = *str - '0';
            ret = ret * 10 + number;
            if (negative) {
                if ( 0 - ret < INT_MIN) {
                    return INT_MIN;
                }
            }
            else {
                if (ret > INT_MAX) {
                    return INT_MAX;
                }
            }
            str++;
        }
        if (negative) {
            return (0 - ret);
        }
        return ret;
}

int main() {
    char* a = "2147483648";
    cout << a << " => ";
    cout << atoi(a) << endl;
    char* b = " b11228552307";
    cout << b << " => ";
    cout << atoi(b) << endl;
}
