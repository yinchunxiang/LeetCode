//
// Created by alexkkk on 2020/1/27.
//
#include <vector>
#include "../util/dbg.h"

using namespace std;

class StockSpanner {
 public:
  StockSpanner() {

  }

  int next(int price) {
    prices_.push_back(price);
    int index = (int)prices_.size() - 1;
    while (prices_[d_.back()] <= price) {
      d_.pop_back();
    }
    int result = index - d_.back();
    d_.push_back(index);
    return result;
  }

 private:
  vector<int> d_{0};
  vector<int> prices_{100001};
};

int main(int argc, char* argv[]) {
  StockSpanner s;
  dbg(s.next(100));
  dbg(s.next(80));
  dbg(s.next(60));
  dbg(s.next(70));
  dbg(s.next(60));
  dbg(s.next(75));
  dbg(s.next(85));
  return 0;
}