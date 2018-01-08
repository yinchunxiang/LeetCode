//
// Created by yinchunxiang on 03/01/2018.
//

#include <map>
#include <iostream>


using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {

    }

    int book(int start, int end) {
        timeline[start] ++;
        timeline[end] --;
        int onging = 0;
        int k = 0;
        for (auto t : timeline) {
            k = max(k, onging += t.second);
        }
        return k;
    }

private:
    map<int, int> timeline;

};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

//MyCalendarThree();
//MyCalendarThree.book(10, 20); // returns 1
//MyCalendarThree.book(50, 60); // returns 1
//MyCalendarThree.book(10, 40); // returns 2
//MyCalendarThree.book(5, 15); // returns 3
//MyCalendarThree.book(5, 10); // returns 3
//MyCalendarThree.book(25, 55); // returns 3


int main(int argc, char *argv[]) {
    MyCalendarThree cal;
    cout << cal.book(10, 20) << endl;
    cout << cal.book(50, 60) << endl;
    cout << cal.book(10, 40) << endl;
    cout << cal.book(5, 15) << endl;
    cout << cal.book(5, 10) << endl;
    cout << cal.book(25, 55) << endl;

    return 0;
}
