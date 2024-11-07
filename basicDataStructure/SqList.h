//
// Created by f2561 on 24-10-8.
//

#ifndef DADS_SQLIST_H
#define DADS_SQLIST_H

namespace ds {
#define dSSQMaxSize 50
template<class ElemType>
class SqList
    {
        const unsigned int MaxSize;
        ElemType *data;		//存放顺序表元素
        int length{-1};					//存放顺序表的长度
    public:
        explicit SqList(unsigned int maxSize) : MaxSize(maxSize) {}
        SqList() : MaxSize(50) {}
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
