//
// Created by f2561 on 24-10-31.
//

#include "LinkedStack.h"

namespace ds {
    template<class ElemType>
    void ds::LinkedStack<ElemType>::init() {//初始化栈
        this->data = new LNode<ElemType>;
        this->data->next = nullptr;
    }

    template<class ElemType>
    void ds::LinkedStack<ElemType>::destroy() {
        LNode<ElemType> *pre = this->data, *p = this->data->next;
        while (p != nullptr) {
            delete pre;
            pre = p;
            p = pre->next;
        }
        delete pre;
    }

    template<class ElemType>
    bool ds::LinkedStack<ElemType>::isEmpty() {
        return this->data->next == nullptr;
    }

    template<class ElemType>
    bool ds::LinkedStack<ElemType>::push(ElemType e) {
        auto *p = new LNode<ElemType>;
        p->data = e;
        p->next = this->data->next;
        this->data->next = p;
        return true;
    }

    template<class ElemType>
    bool ds::LinkedStack<ElemType>::pop(ElemType &e) {
        LNode<ElemType> *p;
        if(this->data->next == nullptr)
            return false;
        p = this->data->next;
        e = p ->data;
        this->data->next = p->next;
        delete p;
        return true;
    }
    template<class ElemType>
    bool LinkedStack<ElemType>::pop() {
        LNode<ElemType> *p;
        if(this->data->next == nullptr)
            return false;
        p = this->data->next;
        this->data->next = p->next;
        delete p;
        return true;
    }

    template<class ElemType>
    bool ds::LinkedStack<ElemType>::getTop(ElemType &e) {
        if (this->next == nullptr)
            return false;
        e = this->data->next->data;
        return true;
    }
} // ds