//
// Created by alexkkk on 2/3/18.
//

#include <vector>
#include <functional>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    //TODO
    std::vector<std::function<int()>> functors;
    functors.emplace_back([&] { return 100; });
    functors.emplace_back([&] { return  10; });
    for (auto& f : functors) {
        cout << f() << endl;
    }
    return 0;
}