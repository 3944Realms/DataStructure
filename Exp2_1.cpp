//
// Created by f2561 on 24-11-6.
//
#include <iostream>
#include "basicDataStructure/LinkedStack.cpp"
#include "basicDataStructure/LinkQueue.cpp"
void reverseStack(ds::LinkedStack<int>& stack);
void deleteFindOnStack(ds::LinkedStack<int>& stack, int e);
void reverseQueue(ds::LinkQueue<int>& queue);

void func_01();

void func_03();

void func_02();

int main() {
    func_01();
    func_02();
    func_03();
    return 0;
}

void func_02() {
    ds::LinkedStack<int> stack{};
    stack.init();
    stack.push(10);
    stack.push(11);
    stack.push(12);
    stack.push(13);
    stack.push(10);
    deleteFindOnStack(stack, 10);
    stack.pop();
    stack.pop();
    stack.pop();
}

void func_03() {
    ds::LinkQueue<int> queue{};
    queue.init();
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    reverseQueue(queue);
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
}

void func_01() {
    ds::LinkedStack<int> stack{};
    stack.init();
    stack.push(10);
    stack.push(6);
    stack.push(4);
    reverseStack(stack);
    stack.pop();
    stack.pop();
    stack.pop();
}

void reverseStack(ds::LinkedStack<int>& stack) {
    int i, n, A[255];
    n=0;
    while(!stack.isEmpty()) {
        n++;
        stack.pop(A[n]);
    }
    for(i=1;  i<=n;  i++)
        stack.push(A[i]);
}

void deleteFindOnStack(ds::LinkedStack<int>& stack, int e) {
    ds::LinkedStack<int> T{};
    int d;
    T.init();
    while(!stack.isEmpty()) {
        stack.pop(d);
        if (d!=e) T.push(d);
    }
    while(!T.isEmpty())
    {
        T.pop(d);
        stack.push(d);
    }

}

void reverseQueue(ds::LinkQueue<int>& queue) {
    ds::LinkedStack<int> stack{};  int d;
    stack.init();
    while(!queue.isEmpty())
    {
        queue.dequeue(d);
        stack.push(d);
    }
    while(!stack.isEmpty()){
        stack.pop(d);
        queue.enqueue(d);
    }

}