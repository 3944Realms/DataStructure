#include "basicDataStructure/SqStack.cpp"
#include <iostream>
#include <vector>
//
// Created by f2561 on 24-11-6.
//
int evalRPN(std::vector<std::string>& tokens);
int main() {
    using namespace std;
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    cout << "Result 1: " << evalRPN(tokens1) << endl;  // 输出 9
    cout << "Result 2: " << evalRPN(tokens2) << endl;  // 输出 6
    cout << "Result 3: " << evalRPN(tokens3) << endl;  // 输出 22
}
int evalRPN(std::vector<std::string>& tokens) {
    ds::SqStack<int> stk(100);  // 栈的最大容量可以设置为100
    stk.init();
    for (const std::string& token : tokens) {
        // 判断当前 token 是否为运算符
        if (token != "+" && token != "-" && token != "*" && token != "/") {
            stk.push(stoi(token));  // 将操作数转换为整数并入栈
        } else {
            // 如果是运算符，从栈中弹出两个操作数
            int b ;
            stk.getTop(b);
            stk.pop();
            int a ;
            stk.getTop(a);
            stk.pop();

            int result = 0;
            // 根据运算符进行运算
            if (token == "+") {
                result = a + b;
            } else if (token == "-") {
                result = a - b;
            } else if (token == "*") {
                result = a * b;
            } else if (token == "/") {
                result = a / b;  // 向零截断的除法
            }

            stk.push(result);  // 运算结果压回栈中
        }
    }
    int ret;
    stk.getTop(ret);
    return ret;  // 返回栈顶元素（即最终结果）
}