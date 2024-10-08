//
// Created by f2561 on 24-10-8.
//

#ifndef DADS_CLINKLIST_H
#define DADS_CLINKLIST_H
#include "CLinkList.h"
#include "LinkNode.h"

namespace ds {

template <class ElemType>
class CLinkList {
public:
    CLinkList() {
        this->head = new LNode<ElemType>;
    }
    LNode<ElemType>* head;
    static CLinkList* createListF(ElemType a[], int n);
    static CLinkList* createListR(ElemType a[], int n);
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

#endif //DADS_CLINKLIST_H
