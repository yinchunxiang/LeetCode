//
// Created by alexkkk on 2019-02-25.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;


/*
 * @lc app=leetcode id=736 lang=cpp
 *
 * [736] Parse Lisp Expression
 *
 * https://leetcode.com/problems/parse-lisp-expression/description/
 *
 * algorithms
 * Hard (43.22%)
 * Total Accepted:    5.1K
 * Total Submissions: 11.7K
 * Testcase Example:  '"(add 1 2)"'
 *
 *
 * You are given a string expression representing a Lisp-like expression to
 * return the integer value of.
 *
 * The syntax for these expressions is given as follows.
 *
 * An expression is either an integer, a let-expression, an add-expression, a
 * mult-expression, or an assigned variable.  Expressions always evaluate to a
 * single integer.
 *
 * (An integer could be positive or negative.)
 *
 * A let-expression takes the form (let v1 e1 v2 e2 ... vn en expr), where let
 * is always the string "let", then there are 1 or more pairs of alternating
 * variables and expressions, meaning that the first variable v1 is assigned
 * the value of the expression e1, the second variable v2 is assigned the value
 * of the expression e2, and so on sequentially; and then the value of this
 * let-expression is the value of the expression expr.
 *
 * An add-expression takes the form (add e1 e2) where add is always the string
 * "add", there are always two expressions e1, e2, and this expression
 * evaluates to the addition of the evaluation of e1 and the evaluation of e2.
 *
 * A mult-expression takes the form (mult e1 e2) where mult is always the
 * string "mult", there are always two expressions e1, e2, and this expression
 * evaluates to the multiplication of the evaluation of e1 and the evaluation
 * of e2.
 *
 * For the purposes of this question, we will use a smaller subset of variable
 * names.  A variable starts with a lowercase letter, then zero or more
 * lowercase letters or digits.  Additionally for your convenience, the names
 * "add", "let", or "mult" are protected and will never be used as variable
 * names.
 *
 * Finally, there is the concept of scope.  When an expression of a variable
 * name is evaluated, within the context of that evaluation, the innermost
 * scope (in terms of parentheses) is checked first for the value of that
 * variable, and then outer scopes are checked sequentially.  It is guaranteed
 * that every expression is legal.  Please see the examples for more details on
 * scope.
 *
 *
 * Evaluation Examples:
 *
 * Input: (add 1 2)
 * Output: 3
 *
 * Input: (mult 3 (add 2 3))
 * Output: 15
 *
 * Input: (let x 2 (mult x 5))
 * Output: 10
 *
 * Input: (let x 2 (mult x (let x 3 y 4 (add x y))))
 * Output: 14
 * Explanation: In the expression (add x y), when checking for the value of the
 * variable x,
 * we check from the innermost scope to the outermost in the context of the
 * variable we are trying to evaluate.
 * Since x = 3 is found first, the value of x is 3.
 *
 * Input: (let x 3 x 2 x)
 * Output: 2
 * Explanation: Assignment in let statements is processed sequentially.
 *
 * Input: (let x 1 y 2 x (add x y) (add x y))
 * Output: 5
 * Explanation: The first (add x y) evaluates as 3, and is assigned to x.
 * The second (add x y) evaluates as 3+2 = 5.
 *
 * Input: (let x 2 (add (let x 3 (let x 4 x)) x))
 * Output: 6
 * Explanation: Even though (let x 4 x) has a deeper scope, it is outside the
 * context
 * of the final x in the add-expression.  That final x will equal 2.
 *
 * Input: (let a1 3 b2 (add a1 1) b2)
 * Output 4
 * Explanation: Variable names can contain digits after the first character.
 *
 *
 *
 * Note:
 * The given string expression is well formatted: There are no leading or
 * trailing spaces, there is only a single space separating different
 * components of the string, and no space between adjacent parentheses.  The
 * expression is guaranteed to be legal and evaluate to an integer.
 * The length of expression is at most 2000.  (It is also non-empty, as that
 * would not be a legal expression.)
 * The answer and all intermediate calculations of that answer are guaranteed
 * to fit in a 32-bit integer.
 *
 */
class Solution {
public:
  std::string GetNextExp(std::string& s, std::string::iterator& start) {
    if ('(' == *start) {
      // 表达式
      int count = 1;
      auto it = start + 1;
      for (; it != s.end() && count > 0; ++it) {
        if (')' == *it) count -= 1;
        if ('(' == *it) count += 1;
      }
      std::string result = std::string(start + 1, it);
      start = it;
      return result;
    }
    // 普通的值

    auto first = start;
    auto last = s.end();
//    auto end = std::find_if(first, last, ::isspace);
    auto end = std::find(first, last, ' ');
    std::string result = std::string(first, end);
//    advance(start, distance<std::string::const_iterator>(start, end));
    start = end;
    return result;
  }


  int eval(string expression, unordered_map<string, int> parameters) {
    // 数字
    if ('-' == expression[0] || (expression[0] >= '0' && expression[0] <= '9')) {
      return std::stoi(expression);
    }
    // 变量
    if ('(' != expression[0]) {
      return parameters[expression];
    }

    string s = expression.substr(1, expression.size() - 2);
    auto start = s.begin();
    string word = GetNextExp(s, start);
    if ("let" == word) {
      while (true) {
        string variable = GetNextExp(s, ++start);
        if (start == s.end()) {
          return eval(variable, parameters);
        }
        string str_value = GetNextExp(s, ++start);
        parameters[variable] = eval(str_value, parameters);
      }
    } else if ("add" == word) {
      auto strx = GetNextExp(s, ++start);
      int x = eval(strx, parameters);
      auto stry = GetNextExp(s, ++start);
      int y = eval(stry, parameters);
      return x + y;
    } else {
      auto strx = GetNextExp(s, ++start);
      int x = eval(strx, parameters);
      auto stry = GetNextExp(s, ++start);
      int y = eval(stry, parameters);
      return x * y;
    }
  }

  int evaluate(string expression) {
    unordered_map<string, int> parameters;
    return eval(expression, parameters);
  }
};

int main(int argc, char* argv[]) {
  Solution s;
  cout << s.evaluate("(let a 2 a)") << endl;
  return 0;
}
