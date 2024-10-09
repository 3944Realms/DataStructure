//
// Created by f2561 on 24-10-9.
//

#include <iostream>
#include "CdLinkList.h"

namespace ds {
    template <class ElemType>
    ds::CdLinkList<ElemType>* ds::CdLinkList<ElemType>::createListF(ElemType *a, int n) {
        auto ret = new CdLinkList<ElemType>;
        DNode<ElemType> *headNode = ret->head, *s;
        headNode->next = nullptr;
        for (int i = 0; i < n; i++) {
            s = new DNode<ElemType>;
            s->data = a[i];
            s->next = headNode->next;
            headNode->next = s;
        }
        s = headNode->next;
        while (s->next != nullptr)
            s = s->next;
        s->next = headNode;
    }

    template<class ElemType>
    ds::CdLinkList<ElemType>* ds::CdLinkList<ElemType>::createListR(ElemType *a, int n) {
        auto ret = new CdLinkList<ElemType>;
        DNode<ElemType> *headNode = ret->head, *s, *r;
        headNode->next = nullptr;
        r = headNode;
        for (int i = 0; i < n; i++) {
            s = new DNode<ElemType>;
            s->data = a[i];
            r->next = s;
            r = s;
        }
        r->next = headNode;
    }

    template<class ElemType>
    void ds::CdLinkList<ElemType>::init() {
       DNode<ElemType> *headNode = this->head;
       if(headNode != nullptr)
           this->destroy();
       headNode = new DNode<ElemType>;
       headNode->prior = headNode->next;
    }

    template<class ElemType>
    void ds::CdLinkList<ElemType>::destroy() {
        DNode<ElemType> *headNode = this->head, *pre = headNode, *p = pre->next;
        while (p != headNode) {
            delete pre;
            pre = p;
            p = pre->next;
        }
        delete pre;
    }

    template<class ElemType>
    bool ds::CdLinkList<ElemType>::isEmpty() {
        DNode<ElemType> *headNode = this->head;
        return headNode->next == headNode;
    }

    template<class ElemType>
    int ds::CdLinkList<ElemType>::getLength() {
        DNode<ElemType> *headNode = this->head, *p = headNode;
        int i = 0;
        while (p->next != headNode) {
            i++;
            p = p->next;
        }
        return i;
    }

    template<class ElemType>
    void ds::CdLinkList<ElemType>::display() {
        DNode<ElemType> *headNode = this->head, *p = headNode->next;
        while (p != headNode) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    template<class ElemType>
    bool ds::CdLinkList<ElemType>::getElem(int i, ElemType &e) {
        DNode<ElemType> *headNode = this->head;
        if (i <= 0 || headNode->next == headNode)
            return false;
        if (i == 1) {
            e = headNode->next->data;
            return true;
        } else {
            int j = 1;
            DNode<ElemType> *p = headNode->next;
            while (j <= i - 1 && p != headNode) {
                j++;
                p = p->next;
            }
            if (p == headNode)
                return false;
            else {
                e = p->data;
                return true;
            }
        }
    }

    template<class ElemType>
    int ds::CdLinkList<ElemType>::locateElem(ElemType e) {
        DNode<ElemType> *headNode = this->head, *p = headNode->next;
        int i = 1;
        while (p != headNode && p->data != e) {
            p = p->next;
            i++;
        }
        return p == headNode ? 0 : i;
    }

    template<class ElemType>
    bool ds::CdLinkList<ElemType>::insertElem(int i, ElemType e) {
        if (i <= 0)
            return false;
        DNode<ElemType> *headNode = this->head, *p = headNode, *s;
        if (p->next == headNode || i == 1) {
            s = new DNode<ElemType>;
            s->data = e;
            s->next = p->next;
            p->next = s;
            return true;
        } else {
            int j = 1;
            p = headNode->next;
            while (j <= i -2 && p != headNode) {
                j++;
                p = p->next;
            }
            if (p == headNode)
                return false;
            else {
                s = new DNode<ElemType>;
                s->data = e;
                s->next = p->next;
                p->next = s;
                return true;
            }
        }
    }

    template<class ElemType>
    bool ds::CdLinkList<ElemType>::deleteElem(int i, ElemType &e) {
        DNode<ElemType> *headNode = this->head;
        if (i <= 0 || headNode->next == headNode)
            return false;
        DNode<ElemType> *p = headNode, *q;
        if (i == 1) {
            q = headNode->next;
            e = q->data;
            headNode->next = q->next;
            delete q;
            return true;
        } else {
             p = headNode->next;
             int j = 1;
             while (j <= i - 2 && p!= headNode) {
                 j++;
                 p = p->next;
             }
             if (p == headNode)
                 return false;
             else {
                 q = p->next;
                 e = q->data;
                 p->next = q->next;
                 delete q;
                 return true;
             }
        }
    }
} // ds