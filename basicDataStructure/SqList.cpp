//
// Created by f2561 on 24-10-8.
//
#include <iostream>
#include "SqList.h"

namespace ds {
    template<class ElemType>
    ds::SqList<ElemType> *ds::SqList<ElemType>::create(ElemType *a, int n) {
        auto *ret = new SqList<ElemType>[n];
        for (int i = 0; i < n; i++)
            ret->data[i] = a[i];
        ret->length = n;
        return ret;
    }

    template<class ElemType>
    void ds::SqList<ElemType>::init() {
        this->length = 0;
    }

    template<class ElemType>
    void ds::SqList<ElemType>::destroy() {
        delete this;
    }

    template<class ElemType>
    bool ds::SqList<ElemType>::isEmpty() {
        return this->length == 0;
    }

    template<class ElemType>
    int ds::SqList<ElemType>::getLength() {
        return this->length;
    }

    template<class ElemType>
    void ds::SqList<ElemType>::display() {
        for (int i = 0; i < this->length; i++) {
            std::cout << this->data[i] << " ";
        }
        std::cout << std::endl;
    }
    template<class ElemType>
    bool ds::SqList<ElemType>::getElem(int i, ElemType &e) {
        if (i < 1 || i > this->length)
            return false;
        e = this->data[i - 1];
        return true;
    }

    template<class ElemType>
    int ds::SqList<ElemType>::locateElem(ElemType e) {
        int i = 0;
        while (i < this->length && this->data[i] != e)
            i++;
        return (i >= this->length) ? 0 : i + 1;
    }

    template<class ElemType>
    bool ds::SqList<ElemType>::insertElem(int i, ElemType e) {
        if (i < 1 || i > this->length + 1 || this->length == dSSQMaxSize)
            return false;
        i--;
        for (int j = this->length; j > i; j--) {
            this->data[j] = this->data[j - 1];
        }
        this->data[i] = e;
        this->length++;
        return true;
    }

    template<class ElemType>
    bool ds::SqList<ElemType>::deleteElem(int i, ElemType &e) {

        if (i < 1 || i > this->length)
            return false;
        e = this->data[--i];
        for (int j = i; j < this->length - 1; j++) {
            this->data[j] = this->data[j + 1];
        }
        this->length--;
        return true;
    }

}//ds