//
// Created by yinchunxiang on 03/02/2018.
//


#include <vector>
#include <unordered_set>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    static constexpr double diff = 0.000001;

    bool judge(vector<double>& v) {
        if (1 == v.size()) return abs(v[0] - 24.0f) < diff;
        auto f0 = [](vector<double>& v, double a, double b) {v.push_back(a + b);};
        auto f1 = [](vector<double>& v, double a, double b) {v.push_back(a * b);};
        auto f2 = [](vector<double>& v, double a, double b) {v.push_back(a - b);};
        auto f3 = [](vector<double>& v, double a, double b) {v.push_back(b - a);};
        auto f4 = [](vector<double>& v, double a, double b) {v.push_back(a / b);};
        auto f5 = [](vector<double>& v, double a, double b) {v.push_back(b / a);};
        vector<function<void(std::vector<double>&, double, double)>> funcs = {f0, f1, f2, f3, f4, f5};
        //@yincx: 下面这个用法编译不过, 原因如下
        // Every lambda has a different type — even if they have the same signature.
        // You must use a run-time encapsulating container such as std::function if you want to do something like that
        // https://stackoverflow.com/questions/7477310/why-cant-i-create-a-vector-of-lambdas-of-the-same-type-in-c11
        //vector<decltype(f0)> funcs = {f0, f1, f2, f3, f4, f5};

        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                vector<double> rest;
                for (int k = 0; k < v.size(); ++k) {
                    if (i == k || j == k) continue;
                    rest.push_back(v[k]);
                }

                for (int m = 0; m < 6; ++m) {
                    if (4 == m && abs(v[j]) < diff) continue;
                    if (5 == m && abs(v[i]) < diff) continue;
                    funcs[m](rest, v[i], v[j]);
                    if (judge(rest)) return true;
                    rest.pop_back();
                }

            }
        }
        return false;

    }

    bool judgePoint24(vector<int>& nums) {
        vector<double> v(nums.begin(), nums.end());
        cout << "--> size: " << v.size() << endl;
        return judge(v);
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    {
        vector<int> input = {4, 1, 8, 7};
        cout << s.judgePoint24(input) << endl;
    }
    {
        vector<int> input = {1, 2, 1, 2};
        cout << s.judgePoint24(input) << endl;
    }
    {
        vector<int> input = {1, 4, 6, 1};
        cout << s.judgePoint24(input) << endl;
    }
    {
        vector<int> input = {1, 9, 1, 2};
        cout << s.judgePoint24(input) << endl;
    }
    return 0;
}
