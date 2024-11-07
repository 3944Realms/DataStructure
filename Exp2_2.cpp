#include "basicDataStructure/SqStack.cpp"
#include "basicDataStructure/SqQueue.cpp"

//
// Created by f2561 on 24-11-6.
//
#include <iostream>
#include <cstring>
bool isPalindromeByStackAndQueue(const char target[]);
class tooLongStrExp : public std::exception {
};
int main() {
    std::string string("223@&122@");
    std::cout<< isPalindromeByStackAndQueue(string.c_str());
}
bool isPalindromeByStackAndQueue(const char target[]) {
    unsigned int len = strlen(target);
    unsigned int splitIndex = -1;

    // 找到'&'的位置
    for (unsigned int i = 0; i < len; i++) {
        if (target[i] == '&') {
            splitIndex = i;
            break;
        }
    }

    // 检查是否包含'&'并且以'@'结束
    if (splitIndex == -1 || target[len - 1] != '@') {
        return false;
    }

    // 使用 SqStack 存储序列1， SqQueue 存储序列2
    ds::SqStack<char> s(splitIndex); // 创建栈，最大容量为序列1的长度
    ds::SqQueue<char> q(len); // 创建队列，最大容量为整个字符串长度
    s.init();
    q.init();

    // 将分隔符'&'之前的字符加入栈
    for (unsigned int i = 0; i < splitIndex - 1; i++) {
        s.push(target[i]);
    }

    // 将分隔符'&'之后的字符加入队列（不包含结束符'@'）
    for (unsigned int i = splitIndex + 1; i < len - 1; i++) {
        q.enqueue(target[i]);
    }

    // 比较栈与队列的字符
    while (!s.isEmpty() && !q.isEmpty()) {
        char stackTop, queueFront;

        // 取栈顶和队列头进行比较
        s.pop(stackTop);
        q.dequeue(queueFront);

        if (stackTop != queueFront) {
            return false;
        }
    }

    // 如果栈和队列都为空，说明匹配成功
    return s.isEmpty() && q.isEmpty();
}