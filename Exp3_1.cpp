#include "basicDataStructure/BTTree.cpp"
#include "constLib/const.h"
//
// Created by f2561 on 24-11-9.
//
char* adr(char cr);
int main() {
    char* list[] = {adr('A'), adr('B'), adr('D'), adr('E'), adr('H'), adr('J'), adr('K'), adr('L'), adr('M'), nullptr, adr('N'),
                    nullptr, nullptr, nullptr, nullptr, nullptr, adr('C'), adr('F'), adr('G'), nullptr, adr('I'),
                    nullptr, nullptr};
    const char inx[] = "((,((,(,(,))))),(,(,)))";
    ds::BTTree<char>* btTree = ds::BTTree<char>::createBTTree(list, inx, 14);
    return 0;
}
char* adr(char cr) {
    return const_cast<char*>(&ASCII_CHAR_ARRAY[cr]);
}