#include <iostream>
#include "basicDataStructure/SqList.cpp"
#include "basicDataStructure/LinkList.cpp"

int sqListExp();
int linkListExp();
int main() {
    return linkListExp();
}
int sqListExp() {
    using namespace std;
    auto *sqList = new ds::SqList<char>;
    char element;
    cout << "顺序表的基本运算如下:\n";
    cout << "(1）初始化顺序表L\n";
    sqList->init();
    cout << "(2）依次插入a、b、c、d、e元素\n";
    sqList->insertElem(1,'a');
    sqList->insertElem(2,'b');
    sqList->insertElem(3,'c');
    sqList->insertElem(4,'d');
    sqList->insertElem(5,'e');
    cout << "(3）输出顺序表L: ";
    sqList->display();
    sqList->getElem(3, element);
    cout << "(4) 输出顺序表L的第3个元素: " << element << endl;
    cout << "(5）在第4个元素的位置上插入f元素\n";
    sqList->insertElem(4, 'f');
    cout << "(6）删除顺序表L的第3个元素\n";
    sqList->deleteElem(3, element);
    cout << "(7) 输出顺序表L: ";
    sqList->display();
    sqList->destroy();
    return 0;
}
int linkListExp() {
    using namespace std;
    auto *lLink = new ds::LinkList<char>;
    char element;
    cout << "单链表的基本运算如下:\n";
    cout << "(1) 初始化单链表h\n";
    lLink->init();
    cout << "(2) 依次采用尾插法插入a,b,c,d,e元素\n";
    lLink->insertElem(1,'a');
    lLink->insertElem(2,'b');
    lLink->insertElem(3,'c');
    lLink->insertElem(4,'d');
    lLink->insertElem(5,'e');
    cout << "(3) 输出单链表h:";
    lLink->display();
    lLink->getElem(3, element);
    cout << "(4) 单链表h的第3个元素:" << element << endl;
    cout << "(5) 在第4个元素位置上插入f元素\n";
    lLink->insertElem(4,'f');
    cout << "(6) 删除h的第3个元素\n";
    lLink->deleteElem( 3, element);
    cout << "(7) 输出单链表h:";
    lLink->display();
    return 0;
}
