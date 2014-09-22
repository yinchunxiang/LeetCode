#include <iostream>
#include <vector> 
#include <numeric> 


using namespace std;

int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        if (n < 1) return 0;
        if (n <= 3) return accumulate(num.begin(), num.end(), 0);
        int distance = INT_MAX;
        int ret = 0;
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 1; ++i) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            
            int a = i; int b = i + 1; int c = n - 1;
            while (b < c) {
                int sum = num[a] + num[b] + num[c];
                cout << "sum: " << sum << endl;
                if (sum > target) {
                    int nd = sum - target;
                    if (nd < distance) {
                        distance = nd;
                        ret = sum;
                    }
                    --c;
                }
                else {
                    int nd = target - sum;
                    if (nd < distance) {
                        distance = nd;
                        ret = sum;
                    }
                    ++b;
                }
            }
        }
        return ret;
}


int main(int argc, const char *argv[])
{
    {
        int a[] = {1, 1, 1, 0};
        vector<int> v(a, a + 4);
        
        cout << threeSumClosest(v, 100) << endl;
    }
    return 0;
}
