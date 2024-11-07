//
// Created by f2561 on 24-11-7.
//

#include "SqStack.h"

namespace ds {
    template<class ElemType>
    void SqStack<ElemType>::init() {
        if (this->data != nullptr) {
            this->destroy();
        }
        this->data = new ElemType[MaxSize];
        this->top = -1;
    }

    template<class ElemType>
    void SqStack<ElemType>::destroy() {
        for (int i = this->top; i >= 0; i--) {
            delete &this->data[i];
        }
        this->top = -1;
    }

    template<class ElemType>
    bool SqStack<ElemType>::isEmpty() {
        return this->top == -1;
    }

    template<class ElemType>
    bool SqStack<ElemType>::push(ElemType e) {
        if (this->top == MaxSize - 1)
            return false;
        this->top++;
        this->data[this->top] = e;
        return true;
    }

    template<class ElemType>
    bool SqStack<ElemType>::pop(ElemType &e) {
        if (this->top == -1)
            return false;
        e = this->data[this->top];
        this->top--;
        return true;
    }

    template<class ElemType>
    bool SqStack<ElemType>::pop() {
        if (this->top == -1)
            return false;
        this->top--;
        return true;
    }

    template<class ElemType>
    bool SqStack<ElemType>::getTop(ElemType &e) {
        if(this->top == -1)
            return false;
        e =this->data[this->top];
        return true;
    }

} // ds