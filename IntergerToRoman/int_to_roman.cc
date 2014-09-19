#include <string>
#include <iostream>

using namespace std;

string intToRoman(int num) {  
    string result;
    char symbol[7] = { 'I','V','X', 'L','C', 'D','M'};  
    int scale = 1000;
    for (int i = 6; i >= 0; i -= 2) {
        int digit = num / scale;
        if (0 == digit) {
            scale /= 10;
            continue;
        }

        switch (digit) {
            case 1: 
            case 2:
            case 3:
                result.append(digit, symbol[i]);
                break;
            case 4:
                result.append(1, symbol[i]);
                result.append(1, symbol[i + 1]);
                break;
            case 5:
                result.append(1, symbol[i + 1]);
                break;
            case 6:
                result.append(1, symbol[i + 1]);
                result.append(1, symbol[i]);
                break;
            case 7:
                result.append(1, symbol[i + 1]);
                result.append(2, symbol[i]);
                break;
            case 8:
                result.append(1, symbol[i + 1]);
                result.append(3, symbol[i]);
                break;
            case 9:
                result.append(1, symbol[i]);
                result.append(1, symbol[i + 2]);
                break;
                break;
        }
        num %= scale;
        scale /= 10;
    }
    return result;
                                                                                                                          
}

int main(int argc, const char *argv[])
{
    cout << intToRoman(1999) << endl;
    
    return 0;
}
