#include <iostream>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0;
    int sum = 0;
    int j = -1;
    for(int i = 0; i < gas.size(); ++i) {
        total = total + gas[i] - cost[i];
        sum = sum + gas[i] - cost[i];
        if ( sum < 0 ) {
            j = i;
            sum = 0;
        }
    }

    if (total < 0 ) {
        return -1;
    }

    return j + 1;

}

int main(int argc, const char *argv[])
{

    return 0;
}

