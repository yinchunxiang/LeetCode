#pragma once

#include <iostream>
#include <vector>

template<typename T>
void printvv(const std::vector<std::vector<T>>& vv) {
    std::cout << "[" << std::endl;
    for (const auto& v : vv) {
        std::cout << "\t[";
        for (const auto& x : v) {
            std::cout << x << ", ";
        }
        std::cout <<"]" << std::endl;

    }
    std::cout << "]" << std::endl;
}
