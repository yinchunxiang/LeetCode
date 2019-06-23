//
// Created by alexkkk on 2019-05-26.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
  struct Number{
    int value;
    int count;
  };

  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    int n = barcodes.size();
    if (1 == n) return barcodes;
    std::unordered_map<int, int> numbers;
    for (int i = 0; i < barcodes.size(); ++i) {
      numbers[barcodes[i]] += 1;
    }
    std::vector<Number> number_list;
    for (auto& pair : numbers) {
      Number number;
      number.value = pair.first;
      number.count = pair.second;
      number_list.push_back(number);
    }

    auto cmp = [](const Number& l, const Number& r) {
      return l.count > r.count;
    };
    sort(begin(number_list), end(number_list), cmp);
    vector<int> bars;
    for (const auto& number : number_list) {
      for (int i = 0; i < number.count; ++i) {
        bars.push_back(number.value);
        cout << bars.back() << ", ";
      }
    }
    cout << endl;

    vector<int> result;
    int right_start = (n + 1)/ 2;
    for (int left_start = 0; left_start < (n + 1) / 2; ++left_start) {
      result.push_back(bars[left_start]);
      if (right_start < n) {
        result.push_back(bars[right_start]);
        right_start += 1;
      }
    }
    return result;

  }

};


int main(int argc, char* argv[]) {
  Solution s;
  vector<int> input {1, 1, 2};
  auto output = s.rearrangeBarcodes(input);
  for (const auto& v : output) {
    std::cout << v << ",";
  }
  std::cout << endl;
  return 0;
}
