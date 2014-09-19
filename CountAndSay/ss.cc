#include <sstream>
#include <iostream>

using namespace std;


int main(int argc, const char *argv[])
{
    stringstream ss;
    int count  = 10;
    char ch = 'x';
    ss << count << ch;
    cout << ss.str() << endl;
    return 0;
}

