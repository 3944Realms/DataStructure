//
// Created by f2561 on 24-11-6.
//

#include "LinkQueue.h"

namespace ds {
    template<class ElemType>
    void LinkQueue<ElemType>::init() {
        if(this->headNode != nullptr) this->destroy();
        auto *headNode_ = this->headNode = new LinkQuNode<ElemType>;
        headNode_->front = headNode_->rear = nullptr;
    }

    template<class ElemType>
    void LinkQueue<ElemType>::destroy() {
        LinkQuNode <ElemType> *headNode_ = this->headNode;
        LNode<ElemType> *pre = headNode_->front, *p;
        if(pre != nullptr) {
            p = pre->next;
            while (p != nullptr) {
                delete pre;
                pre = p; p = p->next;
            }
            delete pre;
        }
    }

    template<class ElemType>
    bool LinkQueue<ElemType>::isEmpty() {
        return this->headNode->rear == nullptr;
    }

    template<class ElemType>
    bool LinkQueue<ElemType>::enqueue(ElemType e) {
        LinkQuNode <ElemType> *headNode_ = this->headNode;
        auto *p = new LNode<ElemType>;
        p->data = e;
        p->next = nullptr;
        if (headNode_->rear == nullptr)
            headNode_->front = headNode_->rear = p;
        else {
            headNode_->rear->next = p;
            headNode_->rear = p;
        }
        return true;//TODO:如果申请内存失败的情况
    }


    template<class ElemType>
    bool LinkQueue<ElemType>::dequeue(ElemType &e) {
        LinkQuNode <ElemType> *headNode_ = this->headNode;
        LNode<ElemType> *t;
        if(headNode_->rear == nullptr)
            return false;
        t = headNode_->front;
        if (headNode_->front == headNode_->rear)
            headNode_->front = headNode_->rear = nullptr;
        else
            headNode_->front = headNode_->front->next;
        e = t->data;
        delete t;
        return true;
    }

    template<class ElemType>
    bool LinkQueue<ElemType>::dequeue() {
        LinkQuNode <ElemType> *headNode_ = this->headNode;
        LNode<ElemType> *t;
        if(headNode_->rear == nullptr)
            return false;
        t = headNode_->front;
        if (headNode_->front == headNode_->rear)
            headNode_->front = headNode_->rear = nullptr;
        else
            headNode_->front = headNode_->front->next;
        delete t;
        return true;
    }

} // ds