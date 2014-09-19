#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int> &height) {
    if (height.empty()) {
        return 0;
    }

    int low = 0;
    int high = height.size() - 1;
    int max_area = 0;

    while (low < high) {
        int area = (high - low) * min(height[low], height[high]);
        if (area > max_area) {
            max_area = area;
        }

        if (height[low] < height[high]) {
            low ++;
        }
        else {
            high --;
        }
    }
    return max_area;
}

int main(int argc, const char *argv[]) 
{
    {
        int a[] = {1, 1};
        vector<int> v(a, a + 2);
        cout << maxArea(v) << endl;
    }
    {
        int a[] = {1, 2, 1};
        vector<int> v(a, a + 3);
        cout << maxArea(v) << endl;
    }
    return 0;
}
