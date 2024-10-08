//
// Created by f2561 on 24-10-8.
//

#ifndef DADS_LINKNODE_H
#define DADS_LINKNODE_H

#include "CLinkList.h"

namespace ds {
    template <class ElemType>
    struct LNode {
        ElemType data;
        struct LNode *next;
    };
    template <class ElemType>
    struct DNode {
        ElemType data;
        struct DNode *prior, *next;
    };
}
#endif //DADS_LINKNODE_H
