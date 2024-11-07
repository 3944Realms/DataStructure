//
// Created by f2561 on 24-11-7.
//

#ifndef DADS_SQQUEUE_H
#define DADS_SQQUEUE_H

namespace ds {
    template<class ElemType>
    class SqQueue {
        const unsigned int MaxSize;
        ElemType* data;
        int front{-1}, rear{-1};
    public:
        explicit SqQueue(unsigned int maxSize) : MaxSize(maxSize) {}
        SqQueue() : MaxSize(50) {}
        void init();
        void destroy();
        bool isEmpty();
        bool enqueue(ElemType e);
        bool dequeue(ElemType &e);
        bool dequeue();
    };

} // ds

#endif //DADS_SQQUEUE_H
