//
// Created by f2561 on 24-10-8.
//

#ifndef DADS_SQLIST_H
#define DADS_SQLIST_H

#include "BDStructure.h"

namespace ds {
#define dSSQMaxSize 50
template<class ElemType>
class SqList
    {
        ElemType data[dSSQMaxSize];		//存放顺序表元素
        int length;					//存放顺序表的长度
    public:
        static SqList* create(ElemType a[], int n);
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


}
#endif //DADS_SQLIST_H
