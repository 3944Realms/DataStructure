//
// Created by f2561 on 24-10-9.
//

#include <iostream>
#include "LinkList.h"

namespace ds {
    template<class ElemType>
    ds::LinkList<ElemType>* ds::LinkList<ElemType>::createListF(ElemType *a, int n) {
        auto* ret = new LinkList<ElemType>;
        LNode<ElemType> *s, *headNode = ret->head;
        headNode->next = nullptr;
        for (int i = 0; i < n; i++) {
            s = new LNode<ElemType>;
            s->data = a[i];
            s->next = headNode->next;
            headNode->next = s;
        }
        return ret;
    }

    template<class ElemType>
    ds::LinkList<ElemType>* ds::LinkList<ElemType>::createListR(ElemType *a, int n) {
        auto* ret = new LinkList<ElemType>;
        LNode<ElemType> *s, *headNode = ret->head, *r;
        headNode->next = nullptr;
        r = headNode;
        for (int i = 0; i < n; i++) {
            s = new LNode<ElemType>;
            s->data = a[i];
            r->next = s;
            r = s;
        }
        r->next = nullptr;
        return ret;
    }

    template<class ElemType>
    void ds::LinkList<ElemType>::init() {
        LNode<ElemType> *headNode = this->head;
        headNode->next = nullptr;
    }

    template<class ElemType>
    void ds::LinkList<ElemType>::destroy() {
        LNode<ElemType> *headNode = this->head, *pre = headNode, *p = pre->next;
        while (p != nullptr) {
            delete pre;
            pre = p;
            p = pre->next;
        }
        delete pre;
    }

    template<class ElemType>
    bool ds::LinkList<ElemType>::isEmpty() {
        LNode<ElemType> *headNode = this->head;
        return headNode->next == nullptr;
    }

    template<class ElemType>
    int ds::LinkList<ElemType>::getLength() {
        int i = 0;
        LNode<ElemType> *headNode = this->head, *p = headNode;
        while (p->next != nullptr) {
            i++;
            p = p->next;
        }
        return i;
    }

    template<class ElemType>
    void ds::LinkList<ElemType>::display() {
        LNode<ElemType> *headNode = this->head, *p = headNode->next;
        while (p != nullptr) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    template<class ElemType>
    bool ds::LinkList<ElemType>::getElem(int i, ElemType &e) {
        int j = 0;
        if (i <= 0)
            return false;
        LNode<ElemType> *headNode = this->head, *p = headNode;
        while (j < i && p != nullptr) {
            j++;
            p = p->next;
        }
        if(p == nullptr)
            return false;
        else {
            e = p->data;
            return true;
        }
    }

    template<class ElemType>
    int ds::LinkList<ElemType>::locateElem(ElemType e) {
        LNode<ElemType> *headNode, *p = headNode->next;
        int i = 1;
        while (p != nullptr && p->data != e) {
            p = p->next;
            i++;
        }
        return p == nullptr ? 0 : i;
    }

    template<class ElemType>
    bool ds::LinkList<ElemType>::insertElem(int i, ElemType e) {
        if(i <= 0)
            return false;
        LNode<ElemType> *headNode = this->head, *p = headNode, *s;
        int j = 0;
        while (j < i - 1 && p != nullptr) {
            j++;
            p = p->next;
        }
        if (p == nullptr)
            return false;
        else {
            s = new LNode<ElemType>;
            s->data = e;
            s->next = p->next;
            p->next = s;
            return true;
        }
    }

    template<class ElemType>
    bool ds::LinkList<ElemType>::deleteElem(int i, ElemType &e) {
        if (i <= 0)
            return false;
        int j = 0;
        LNode<ElemType> *headNode = this->head, *p = headNode, *q;
        while (j < i - 1 && p != nullptr) {
            j++;
            p = p->next;
        }
        if (p == nullptr)
            return false;
        else {
            q = p->next;
            if (q == nullptr)
                return false;
            e = q->data;
            p->next = q->next;
            delete q;
            return true;
        }
    }

} // ds