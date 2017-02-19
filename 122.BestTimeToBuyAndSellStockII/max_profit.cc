#include <iostream>
#include <vector>

using namespace std;

/*
int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2) {
        return 0;
    }
    vector<int> f1;
    int profit = 0;
    int curr_min_price = prices[0];

    for(int i = 1; i < n; ++i) {
        int diff = prices[i] - curr_min_price;
        if (diff > profit){
            profit = diff;
        }

        if (prices[i] < curr_min_price){
            curr_min_price = prices[i];
        }
        f1.push_back(profit);
    }

    vector<int> f2;
    int curr_max_price = prices[n-1];
    profit = 0;
    for(int i = n - 2; i >= 0; --i){
        int diff = curr_max_price - prices[i];
        if (diff > profit){
            profit = diff;
        }

        if (prices[i] > curr_max_price){
            curr_max_price = prices[i];
        }
        f2.push_back(profit);
    }
    
    int max = 0;
    for (int i = 0; i < n; ++i){
        int curr_sum = f1[i] + f2[i];
        if (curr_sum > max){
            max = curr_sum;
        }
    }

    return max;

}
*/

    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }   
        vector<int> f1; 
        int profit = 0;
        int curr_min_price = prices[0];
    
        for(int i = 1; i < n; ++i) {
            int diff = prices[i] - curr_min_price;
            if (diff > profit){
                profit = diff;
            }   
    
            if (prices[i] < curr_min_price){
                curr_min_price = prices[i];
            }   
            f1.push_back(profit);
        }   
    
        vector<int> f2; 
        int curr_max_price = prices[n-1];
        profit = 0;
        for(int i = n - 2; i >= 0; --i){
            int diff = curr_max_price - prices[i];
            if (diff > profit){
                profit = diff;
            }   
    
            if (prices[i] > curr_max_price){
                curr_max_price = prices[i];
            }   
            f2.push_back(profit);
        }   
            
        int max = 0;
        for (int i = 0; i < n; ++i){
            int curr_sum = f1[i] + f2[i];
            if (curr_sum > max){
                max = curr_sum;
            }   
        }   
    
        return max;        
    }

int main(int argc, const char *argv[])
{
    int a[] = {1, 2};
    vector<int> va(a, a+2);
    cout << maxProfit(va) << endl;
    return 0;
}
