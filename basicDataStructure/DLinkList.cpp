//
// Created by f2561 on 24-10-9.
//

#include <iostream>
#include "DLinkList.h"

namespace ds { template<class ElemType>
    ds::DLinkList<ElemType>* ds::DLinkList<ElemType>::createListF(ElemType *a, int n) {
        auto ret = new DLinkList<ElemType>;
        DNode<ElemType> *headNode = ret->head, *s;
        headNode->prior = headNode->next = nullptr;
        for (int i = 0; i < n; i++) {
           s = new DNode<ElemType>;
           s->data = a[i];
           s->next = headNode->next;
           if (headNode->next != nullptr)
               headNode->next->prior = s;
           headNode->next = s;
           s->prior = headNode;
        }
        return ret;
    }

    template<class ElemType>
    ds::DLinkList<ElemType>* ds::DLinkList<ElemType>::createListR(ElemType *a, int n) {
        auto ret = new DLinkList<ElemType>;
        DNode<ElemType> *headNode = ret->head, *s, *r;
        headNode->prior = headNode->next = nullptr;
        r = headNode;
        for (int i = 0; i < n; i++) {
            s = new DNode<ElemType>;
            s->data = a[i];
            r->next = s; s->prior = r;
            r = s;
        }
        r->next = nullptr;
        return ret;
    }

    template<class ElemType>
    void ds::DLinkList<ElemType>::init() {
        DNode<ElemType> *headNode = this->head;
        if(headNode != nullptr)
            this->destroy();
        headNode = new DNode<ElemType>;
        headNode->prior = headNode->prior = nullptr;
    }

    template<class ElemType>
    void ds::DLinkList<ElemType>::destroy() {
        DNode<ElemType> *headNode = this->head, *pre = headNode, *p = pre->next;
        while (p != nullptr) {
            delete pre;
            pre = p;
            p = pre->next;
        }
        delete p;
    }

    template<class ElemType>
    bool ds::DLinkList<ElemType>::isEmpty() {
        DNode<ElemType> *headNode = this->head;
        return headNode->next == nullptr;
    }

    template<class ElemType>
    int ds::DLinkList<ElemType>::getLength() {
        DNode<ElemType> *headNode = this->head, *p = headNode;
        int i = 0;
        while (p->next != nullptr) {
            i++;
            p = p->next;
        }
        return i;
    }

    template<class ElemType>
    void ds::DLinkList<ElemType>::display() {
        DNode<ElemType> *headNode = this->head, *p = headNode->next;
        while (p != nullptr) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    template<class ElemType>
    bool ds::DLinkList<ElemType>::getElem(int i, ElemType &e) {
        if(i <= 0)
            return false;
        DNode<ElemType> *headNode = this->head, *p = headNode;
        int j = 0;
        while (j < 1 && p != nullptr) {
            j++;
            p = p->next;
        }
        if (p == nullptr)
            return false;
        else {
            e = p->data;
            return true;
        }
    }

    template<class ElemType>
    int ds::DLinkList<ElemType>::locateElem(ElemType e) {
        int i = 1;
        DNode<ElemType> *headNode = this->head, *p = headNode->next;
        while (p != nullptr && p->data != e) {
            i++;
            p = p->next;
        }
        return p == nullptr ? 0 : i;
    }

    template<class ElemType>
    bool ds::DLinkList<ElemType>::insertElem(int i, ElemType e) {
        if (i <= 0)
            return false;
        DNode<ElemType> *headNode = this->head, *p = headNode, *s;
        int j = 0;
        while (j < i - 1 && p != nullptr) {
            j++;
            p = p->next;
        }
        if (p == nullptr)
            return false;
        else {
            s = new DNode<ElemType>;
            s->data = e;
            s->next = p->next;
            if(p->next != nullptr)
                p->next->prior = s;
            s->prior = p;
            p->next = s;
            return true;
        }
    }

    template<class ElemType>
    bool ds::DLinkList<ElemType>::deleteElem(int i, ElemType &e) {
        if (i <= 0)
            return false;
        DNode<ElemType>* headNode = this->head, *p = headNode, *q;
        int j = 0;
        while (j < i - 1 && p != nullptr) {
            j++;
            p = p->next;
        }
        if (p == nullptr)
            return false;
        else {
            q = p->next;
            if(q == nullptr)
                return false;
            e = q->data;
            p->next = q->next;
            if (p->next != nullptr)
                p->next->prior = p;
            delete q;
            return true;
        }
    }


} // ds