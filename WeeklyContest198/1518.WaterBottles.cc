//
// Created by alexkkk on 2020/7/19.
//

#include <iostream>
#include "../util/dbg.h"

using namespace std;

class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int result = 0;
    int num_full_bottles = numBottles;
    int num_empty_bottles = 0;
    while (num_full_bottles > 0) {
      result += num_full_bottles;
      num_empty_bottles += num_full_bottles;
      num_full_bottles = num_empty_bottles / numExchange;
      num_empty_bottles -= num_full_bottles * numExchange;
    }
    return result;
  }

  void Check(int num_bottles, int num_exchange) {
    dbg(num_bottles, num_exchange);
    std::cout << numWaterBottles(num_bottles, num_exchange) << std::endl;
  }
};



int main(int argc, char* argv[]) {
  Solution s;

  s.Check(9, 3);
  s.Check(15, 4);
  s.Check(5, 5);
  s.Check(2, 3);

  return 0;
}

