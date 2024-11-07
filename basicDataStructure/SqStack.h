//
// Created by f2561 on 24-11-7.
//

#ifndef DADS_SQSTACK_H
#define DADS_SQSTACK_H

namespace ds {

    template<class ElemType>
    class SqStack {
        const unsigned int MaxSize;
        ElemType* data;
        int top {-1};
    public:
        explicit SqStack(unsigned int maxSize): MaxSize(maxSize) {}
        SqStack(): MaxSize(50) {}
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

#endif //DADS_SQSTACK_H
