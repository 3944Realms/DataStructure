//
// Created by f2561 on 24-10-9.
//

#ifndef DADS_LINKLIST_H
#define DADS_LINKLIST_H

#include "LinkNode.h"

namespace ds {
    template <class ElemType>
    class LinkList {
        LNode<ElemType> *head;
    public:
        LinkList() {
            this->head = new LNode<ElemType>;
            this->head->next = nullptr;
        }
        static LinkList* createListF(ElemType a[], int n);
        static LinkList* createListR(ElemType a[], int n);
        void init();
        void destroy();
        bool isEmpty();
        int getLength();
        void display();
        bool getElem(int i, ElemType &e);
        int locateElem(ElemType e);
        bool insertElem(int i, ElemType e);
        bool deleteElem(int i, ElemType &e);
    };



} // ds

#endif //DADS_LINKLIST_H
