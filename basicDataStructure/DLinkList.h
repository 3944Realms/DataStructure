//
// Created by f2561 on 24-10-9.
//

#ifndef DADS_DLINKLIST_H
#define DADS_DLINKLIST_H

#include "LinkNode.h"

namespace ds {

    template <class ElemType>
    class DLinkList {
        DNode<ElemType> *head;
    public:
        DLinkList() {
            this->head = new DNode<ElemType>;
            this->head->next = nullptr;
        }
        static DLinkList* createListF(ElemType a[], int n);
        static DLinkList* createListR(ElemType a[], int n);
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

#endif //DADS_DLINKLIST_H
