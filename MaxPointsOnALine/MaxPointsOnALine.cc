#include <iostream>
#include <vector>
#include <tr1/unordered_map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
int maxPoints(vector<Point> &points) {
    if (points.empty()) {
        return 0;
    }
    int max = 0;
    int size = points.size();
    for(int i = 0; i < size; ++i) {
        std::tr1::unordered_map<double, int> slope_map;
        int point_max = 0;
        int special = 0;
        int plus = 0;
        for(int j = 0; j < size; ++j) {
            if (i == j) {
                continue;
            }

            if (points[j].x == points[i].x && points[j].y == points[i].y) {
                plus ++;
                continue;
            }

            if (points[j].x == points[i].x) {
                special += 1;
                point_max = special >  point_max ? special: point_max;
                continue;
            }

            double slope = 1.0 * (points[j].y - points[i].y)/(points[j].x - points[i].x);
            slope_map[slope] += 1;
            point_max = slope_map[slope] >  point_max ? slope_map[slope] : point_max;
            cout << "[" << i << "," << j << "]: " << slope << endl;
        }
        int real_point_max = point_max + plus;
        max = real_point_max > max ? real_point_max : max;
        cout << "plus: " << plus << endl;
        cout << "special: " << special << endl;
        cout << "=============================================================" << endl;
    }

    return max + 1;
};

int main() {
    vector<Point> vec;
    Point a(0,0);
    vec.push_back(a);
    Point b(-1, -1);
    vec.push_back(b);
    Point c(2, 2);
    vec.push_back(c);
    cout << maxPoints(vec) << endl;

    vec.clear();
    Point zero(0,0);
    vec.push_back(zero);
    vec.push_back(zero);
    cout << maxPoints(vec) << endl;

    Point arr[] = {Point(84,250),Point(0,0),Point(1,0),Point(0,-70),Point(0,-70),Point(1,-1),Point(21,10),Point(42,90),Point(-42,-230)};
    vector<Point> test1(arr, arr + sizeof(arr) / sizeof(Point));
    cout << maxPoints(test1) << endl;

}

