#include <string>
#include <iostream>
#include <numeric>

int main(int argc, char const* argv[]) {
    std::string input = "abc";
    std::cout << "{" <<  input.substr(3, 3) << "}" << std::endl;
    std::cout << std::gcd<int, int>(2, 4) << std::endl;


    return 0;
}
