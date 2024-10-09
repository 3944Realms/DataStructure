//
// Created by f2561 on 24-10-9.
//

#ifndef DADS_CDLINKLIST_H
#define DADS_CDLINKLIST_H

#include "LinkNode.h"

namespace ds {

    template <class ElemType>
    class CdLinkList {
        DNode<ElemType> *head;
    public:
        CdLinkList() {
            this->head = new DNode<ElemType>;
            this->head->next = this->head;

        }
        static CdLinkList* createListF(ElemType a[], int n);
        static CdLinkList* createListR(ElemType a[], int n);
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

#endif //DADS_CDLINKLIST_H
