#include <iostream>
#include <string>
#include <vector>
#include <sstream>



using namespace std;


class BigInt{
    public:
        BigInt(const string& x){
            int n = x.size();
            for (int i = n; i > 0; i -= radix_size_) { // [i - radix_size_, i)
                int low = max(i - radix_size_ , 0);
                int64_t value = 0;
                for (int j = low; j < i; ++j) {
                    value = value * 10 + x[j] - '0';
                }
                big_int_.push_back(value);
            } 
        }

        BigInt(const vector<int64_t> &bigint){
            big_int_ = bigint;
        }

        static BigInt Multiply(const BigInt& x, const BigInt& y);

        string ToString() {
            stringstream ss;
            for (int i = big_int_.size() - 1; i >= 0; --i) {
                ss << big_int_[i];
            }

            return ss.str();
        }

        vector<int64_t> big_int_;

    private:
        static const int64_t scale_;
        const static int radix_size_;

};

const int64_t BigInt::scale_ = 1000000000;
const int BigInt::radix_size_ = 9;

BigInt BigInt::Multiply(const BigInt& x, const BigInt& y) {
    int nx = x.big_int_.size();
    int ny = y.big_int_.size();
    vector<int64_t> result( nx + ny, 0);
    for (int i = 0; i < nx; ++i) {
        for (int j = 0; j < ny; ++j) {
            int64_t product = x.big_int_[i] * y.big_int_[j];
            int index = i + j;
            result[index] += product;
            if (result[index] >= scale_) {
                result[index + 1] += result[index] / scale_;
                result[index] %= scale_;
            }
        }
    }
    // remove zero
    while (result.back() == 0 && result.size() > 1) {
        result.pop_back();
    } 
    return BigInt(result);
}

string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    if (0 == n1) {return num1; }
    if (0 == n2) {return num2; }
    //printf("n1:%d n2:%d\n", n1, n2);

    string result(n1 + n2, '0');
    //cout << "result: " << result << endl;
    int carry = 0;
    for (int i = n1 - 1; i >= 0; --i) {
        for (int j = n2 - 1; j >= 0; --j) {
            //printf("num1[%d]:%d num2[%d]:%d\n", i, num1[i]-'0', j, num2[j] - '0');
            int product = (num1[i] - '0') * (num2[j] - '0');
            //cout << "product: " << product << endl;
            int index = n1 + n2 - 1 - (n1 - 1 -i) - (n2 - 1 -j);
            //cout << "index: " << index << endl;
            int sum = result[index] - '0' + product;
            //cout << "sum: " << sum << endl;
            if (sum >= 10) {
                int carry = sum / 10;
                result[index] = '0' + sum % 10 ;
                while (carry > 0) {
                    int sum  = carry + result[index - 1] - '0';
                    carry = sum / 10;
                    result[index - 1] = '0' + sum % 10;
                    index --;
                }
            }
            else {
                result[index] = '0' + sum;
            }

            //cout << "result: " << result << endl;
        }
    }

    int start = 0;
    while('0' == result[start] && start < n1 + n2 - 1) {
        ++start;
    }
    return result.substr(start);
}

int main(int argc, const char *argv[])
{
    cout << multiply("11", "11") << endl;
    cout << multiply("99", "99") << endl;
    cout << multiply("123", "456") << endl;
    BigInt x("123");
    BigInt y("456");
    cout << BigInt::Multiply(x, y).ToString() << endl;

    return 0;
}
