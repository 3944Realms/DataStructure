//
// Created by f2561 on 24-11-7.
//

#include "SqQueue.h"

namespace ds {

    template<class ElemType>
    void SqQueue<ElemType>::init() {
        this->destroy();
        this->data = new ElemType[MaxSize];
        this->front = this->rear = 0;
    }

    template<class ElemType>
    void SqQueue<ElemType>::destroy() {
        if(!this->isEmpty()) {
            for (int i = this->rear; i != this->front; (--i) %= MaxSize) {
                delete &this->data[i];
            }
        }
    }

    template<class ElemType>
    bool SqQueue<ElemType>::isEmpty() {
        return this->front == this->rear;
    }

    template<class ElemType>
    bool SqQueue<ElemType>::enqueue(ElemType e) {
        if((this->rear + 1)% MaxSize == this->rear)
            return false;
        this->rear = (this->rear + 1) % MaxSize;
        this->data[this->rear] = e;
        return true;
    }

    template<class ElemType>
    bool SqQueue<ElemType>::dequeue(ElemType &e) {
        if(this->front == this->rear)
            return false;
        this->front = (this->front + 1) % MaxSize;
        e = this->data[this->front];
        return true;
    }

    template<class ElemType>
    bool SqQueue<ElemType>::dequeue() {
        if(this->front == this->rear)
            return false;
        this->front = (this->front + 1) % MaxSize;
        return true;
    }

} // ds