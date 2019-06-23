//
// Created by alexkkk on 2019-06-23.
//
/*
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Example 1:

Input: "112358"
Output: true
Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: The additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Follow up:
How would you handle overflow for very large input integers?
*/

/**
 * 思路：整体思路仍然是回溯，回溯就是怎么想好递归
 *
 * 在前面2个数字确定的情况下，递归判断剩下的string是不是以sum开头
 * 最少3个数字
 * 剩下的string为空代表成功
 */

class Solution {
public:
  bool isAdditive(long num1, long num2, std::string remain) {
    // 第一个次的时候不可能是空字符串，因为上面已经给预留了第三个数字的长度
    // 后续继续递归的时候，才有可能是空，即到了字符串尾部的时候
    if (remain.empty()) return true;
    // 这里不需要判断 '0' 开头， 因为 "000"情况，这个就有问题了
    // 不是"000"的情况的时候，在下面比较字符串的时候，也不会通过，所以没必要在这里判读
//    if ('0' == remain[0]) return false;
    long sum = num1 + num2;
    auto str_sum = std::to_string(sum);
    if (strncmp(str_sum.c_str(), remain.c_str(), str_sum.size())) return false;
    return isAdditive(num2, sum, remain.substr(str_sum.size()));
  }

  bool isAdditiveNumber(string num) {
    int N = num.size();
    if (N < 3) return false;
    // i 代表第一个数字的长度
    for (int i = 1; i <= N/2; ++i) { // 第一个数的长度
      if (i >= 2 && num[0] == '0') break;
      // 第二个数字是 num[i,j), j是结束位置
      // 第三个数字的长度需要大于等于 第一个和第二个数字的长度
      for (int j = i + 1; N - j >= i && N - j >= (j - i); ++j) {
        // 第二个数字的长度>=2, 但是第一个为0的情况
        if (j - i >= 2 && '0' == num[i]) break;
        long num1 = std::stol(num.substr(0, i));
        long num2 = std::stol(num.substr(i, j - i));
        if (isAdditive(num1, num2, num.substr(j))) return true;
      }
    }
    return false;

  }
};

