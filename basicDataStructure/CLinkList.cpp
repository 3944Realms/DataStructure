//
// Created by f2561 on 24-10-8.
//

#include <iostream>
#include "CLinkList.h"

namespace ds {
    template <class ElemType>
    ds::CLinkList<ElemType>* ds::CLinkList<ElemType>::createListF(ElemType *a, int n) {//头插法
        auto *ret = new CLinkList<ElemType>;//Head节点
        LNode<ElemType> *s;
        LNode<ElemType> *headNode = ret->head;
        headNode->next = nullptr;
        for (int i = 0; i < n; i++) {
            s = new LNode<ElemType>;
            s->data = a[i];
            s->next = headNode->next;//新节点指向Head节点的next节点
            headNode->next = s;
        }
        s = headNode->next;
        while (s->next != nullptr)
            s = s->next;
        s->next = ret;//形成循环
        return ret;
    }

    template <class ElemType>
    ds::CLinkList<ElemType>* ds::CLinkList<ElemType>::createListR(ElemType *a, int n) {
        auto *ret = new CLinkList<ElemType>;
        LNode<ElemType> *headNode = ret->head;
        LNode<ElemType> *s, *r;
        r = headNode;//r为尾节点指针
        for (int i = 0; i < n; i++) {
            s = new LNode<ElemType>;
            s->data = a[i];
            r->next = s;//尾节点的next指针指向新节点
            r = s;
        }
        r->next = headNode;//形成循环
    }

    template <class ElemType>
    void ds::CLinkList<ElemType>::init() {
        auto *headNode = new LNode<ElemType>;
        this->head = headNode;
        headNode->next = headNode;
    }

    template <class ElemType>
    void ds::CLinkList<ElemType>::destroy() {
        LNode<ElemType> *headNode = this->head;
        LNode<ElemType> *pre = headNode, *p = pre->next;
        while (p != headNode) {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "DanglingPointer"
            delete pre;
#pragma clang diagnostic pop
            pre = p;
            p = pre->next;
        }
        delete pre;
    }

    template <class ElemType>
    bool ds::CLinkList<ElemType>::isEmpty() {
        LNode<ElemType> *headNode = this->head;
        return headNode == headNode->next;
    }

    template <class ElemType>
    int ds::CLinkList<ElemType>::getLength() {
        LNode<ElemType> *headNode = this->head, *p = headNode;
        int i = 0;
        while (p->next != headNode) {
            i++;
            p = p->next;
        }
        return i;
    }

    template <class ElemType>
    void ds::CLinkList<ElemType>::display() {
        LNode<ElemType> *headNode = this->head, *p = headNode;
        while (p != headNode) {
            std::cout << p->data << " ";
        }
        std::cout << std::endl;
    }

    template <class ElemType>
    bool ds::CLinkList<ElemType>::getElem(int i, ElemType &e) {
        int j = 1;
        LNode<ElemType> *headNode = this->head, *p = headNode->next;
        if (i <= 0 || headNode->next == headNode)
            return false;
        if (i == 1) {
            e = headNode->next->data;
            return true;
        } else {
          while (j <= i - 1 && p != headNode) {
              j++;
              headNode = headNode->next;
          }
          if(p == headNode)
              return false;
          else {
              e = p->data;
              return true;
          }
        }
    }

    template <class ElemType>
    int ds::CLinkList<ElemType>::locateElem(ElemType e) {
        LNode<ElemType> *headNode = this->head, *p = headNode->next;
        int i = 1;
        while (p != headNode && p->data != e) {
            p = p->next;
            i++;
        }
        return p == headNode ? 0 : i;
    }

    template <class ElemType>
    bool ds::CLinkList<ElemType>::insertElem(int i, ElemType e) {
        LNode<ElemType> *headNode = this->head, *p = headNode, *s;
        if (i <= 0)
            return false;
        if (p->next == headNode || i == 1) { //空链表或 i=1
            s = new LNode<ElemType>;
            s->data = e;
            s->next = p->next;
            p->next = s;
            return true;
        } else {
            p = headNode->next;
            int j = 1;
            while (j <= i - 2 && p != headNode) {
                j++;
                p = p->next;
            }
            if (p == headNode)
                return false;
            else {
                s = new CLinkList<ElemType>;
                s->data = e;
                s->next = p->next;
                p->next = s;
                return true;
            }
        }

    }

    template <class ElemType>
    bool ds::CLinkList<ElemType>::deleteElem(int i, ElemType &e) {
        LNode<ElemType> *headNode = this->head, *p = headNode, *q;
        if (i <= 0 || headNode->next == headNode)
            return false;
        if (i == 1) {
            q = headNode->next;
            e = q->data;
            headNode->next = q->next;
            delete q;
            return true;
        }
        else {
            p = headNode;
            int j = 1;
            while (j <= i - 2 && p != headNode) {
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
}// ds
