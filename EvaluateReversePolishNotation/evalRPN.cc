#include <iostream>
#include <vector> 
#include <stack> 

using namespace std;


int is_operand(const string& op) {
    if (op == "+" || op == "-" || op == "*" || op == "/") {
        return 1;
    }
    return 0; 
}

int get_result(int left, int right, const string& operand) {
    if (operand == "+") {
        return left + right;
    }
    
    if (operand == "-") {
        return left - right;
    }
    if (operand == "*") {
        return left * right;
    }
    if (operand == "/") {
        return left / right;
    }

    return 0;
}


int evalRPN(vector<string> &tokens) {
    stack<int> numbers;
    for(int i = 0; i< tokens.size();++i) {
        if (is_operand(tokens[i])){
            if (numbers.size() >= 2) {
                int right = numbers.top();
                numbers.pop();
                int left = numbers.top();
                numbers.pop();
                int result = get_result(left, right, tokens[i]);
                numbers.push(result);
                cout << left << " " << tokens[i] << " " << right << " = " << result << endl;
            }
            else {
                cout << "should not be here" << endl;
            }
        }
        else {  
            numbers.push(atoi(tokens[i].c_str()));
        }
    }

    return numbers.top();
}

int main(int argc, const char *argv[])
{
    string a[] = {"2", "1", "+", "3", "*"};
    vector<string> va(a, a+5);
    cout << evalRPN(va) << endl;
    string b[] = {"4", "13", "5", "/", "+"};
    vector<string> vb(b, b+5);
    cout << evalRPN(vb) << endl;
    string c[] = {"3","-4","+"};
    vector<string> vc(c, c+3);
    cout << evalRPN(vc) << endl;
    return 0;
}

