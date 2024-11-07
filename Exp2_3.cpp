//
// Created by f2561 on 24-11-6.
//
#include <iostream>
#include <unordered_map>
#include "basicDataStructure/SqStack.cpp"
bool isValidClosingBracket(const std::string& target);
int main() {
    using namespace std;
    string s1 = "()";
    string s2 = "()[]{}";
    string s3 = "(]";
    string s4 = "([)]";
    cout << "Is '()' valid? " << (isValidClosingBracket(s1) ? "Yes" : "No") << endl;
    cout << "Is '()[]{}' valid? " << (isValidClosingBracket(s2) ? "Yes" : "No") << endl;
    cout << "Is '(]' valid? " << (isValidClosingBracket(s3) ? "Yes" : "No") << endl;
    cout << "Is '([)]' valid? " << (isValidClosingBracket(s4) ? "Yes" : "No") << endl;
}
bool isValidClosingBracket(const std::string& target) {
    // 定义一个哈希映射，存储每个右括号与左括号的对应关系
    std::unordered_map<char, char> bracketPairs = {{')', '('}, {'}', '{'}, {']', '['}};

    ds::SqStack<char> stack(target.length());  // 创建一个栈来存储左括号
    stack.init();
    for (char c : target) {
        if (bracketPairs.count(c)) {  // 如果是右括号
            // 如果栈为空或者栈顶的左括号不匹配，则返回false
            char tem;
            stack.getTop(tem);
            if (stack.isEmpty() || tem != bracketPairs[c]) {
                return false;
            }
            stack.pop();  // 弹出栈顶元素
        } else {  // 如果是左括号
            stack.push(c);
        }
    }

    // 如果栈为空，则所有括号均已匹配，返回true；否则返回false
    return stack.isEmpty();
}