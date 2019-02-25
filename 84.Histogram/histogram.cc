#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int largestRectangleArea(vector<int> &height) {
    int max_area = 0;
    for (int i = 0; i < height.size(); ++i) {
        int sub_max_area = 0; 
        int prev_min = INT_MAX;
        for (int j = i; j >= 0; j --) {
            int l = i - j + 1;
            int h = min(height[j], prev_min);
            int area = l * h;
            //cout << "sub area: " << area << endl;
            if (area > max_area){
                max_area = area;
            }
            prev_min = h;
        }
    }
    return max_area;
}

int largestRectangleArea2(vector<int> &height) {
    int n = height.size();
    if (0 == n) return 0;
    if (1 == n) return height[0];
    height.push_back(0);
    int max_area = 0;
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        if (s.empty() || height[i] >= height[s.top()]) {
            s.push(i);//push index
        }
        else {
            int index = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            int h = height[index];
            max_area = max(max_area, width * h);
            cout << "width: " << width << " height: " << height[index] << endl;
            cout << "max_area : " << max_area << endl;
            i --;//Do not let i increase
        }
    }

    return max_area;
}

int main(int argc, const char *argv[])
{
    int input[] = {2,1,5,6,2,3};
    vector<int> v(input, input + 6);
    cout << largestRectangleArea(v) << endl;
    cout << largestRectangleArea2(v) << endl;
    return 0;
}


