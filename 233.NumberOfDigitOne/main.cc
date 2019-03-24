  //
// Created by yinchunxiang on 2019-03-24.
//

/**
  233. Number of Digit One
  Hard

  Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

  Example:

  Input: 13
  Output: 6
  Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

 */

int countDigitOne(int n) {
  if (n <= 0) return 0;
  if (n < 10) return 1;

  int base = 10;
  int count = 0;
  while (n / base >= 10) {
    base *= 10;
  }

  // n 的第一个数字
  int num = n / base;

  // 包含高位的时候的1
  if (1 == num) {
    count += (n % base + 1) + countDigitOne(base - 1);
  } else {
    count += num * countDigitOne(base - 1) + base;
  }

  // 不包含高位的时候
  count += countDigitOne(n - num * base);
  return count;
}