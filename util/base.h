#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

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


template<typename T>
void printv(const std::vector<T>& v) {
  std::cout << "[";
  for (const auto& x : v) {
    std::cout << x << ", ";
  }
  std::cout <<"]" << std::endl;
}

template<typename T>
void prints(const std::unordered_set<T>& v) {
  std::cout << "[";
  for (const auto& x : v) {
    std::cout << x << ", ";
  }
  std::cout <<"]" << std::endl;
}
