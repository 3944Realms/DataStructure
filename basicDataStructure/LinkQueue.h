//
// Created by f2561 on 24-11-6.
//

#ifndef DADS_LINKQUEUE_H
#define DADS_LINKQUEUE_H

#include "LinkNode.h"
#include "LinkList.h"

namespace ds {
    template<class ElemType>
    struct LinkQuNode {
        LNode<ElemType> *front;
        LNode<ElemType> *rear;
    };

    template<class ElemType>
    class LinkQueue {
        LinkQuNode<ElemType>* headNode;
    public:
        void init();
        void destroy();
        bool isEmpty();
        bool enqueue(ElemType e);
        bool dequeue(ElemType &e);//先判空后出栈
        bool dequeue();
    };




} // ds

#endif //DADS_LINKQUEUE_H
