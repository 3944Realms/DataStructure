//
// Created by f2561 on 24-10-31.
//

#ifndef DADS_LINKEDSTACK_H
#define DADS_LINKEDSTACK_H

#include "LinkList.cpp"

namespace ds {
    template<class ElemType>
    class LinkedStack {
        LNode<ElemType>* data;
    public:
        void init();
        void destroy();
        bool isEmpty();
        bool push(ElemType e);
        bool pop(ElemType &e);//先判空后出栈
        bool pop();
        bool getTop(ElemType &e);
    };



} // ds

#endif //DADS_LINKEDSTACK_H
