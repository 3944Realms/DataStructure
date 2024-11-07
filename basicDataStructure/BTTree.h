//
// Created by f2561 on 24-10-31.
//

#ifndef DADS_BTTREE_H
#define DADS_BTTREE_H

#include <iostream>

namespace ds {

    template<class ElemType>
    struct BTNode { //二叉树节点
        ElemType data;
        struct BTNode* lChild;
        struct BTNode* rChild;
        void destroy() {
            if (this->lChild != nullptr) this->lChild->destroy();
            if (this-rChild != nullptr) this->rChild->destroy();
            delete data;
        }
        BTNode<ElemType>* findNode(ElemType target) {
            if (this->data == target)
                return this;
            else {
                BTNode<ElemType> *p;
                if (this->lChild != nullptr) {
                    p = this->lChild->findNode(target);
                }
                if (p == nullptr && p->rChild != nullptr) {
                    p = this->rChild->findNode(target);
                }
                return p;
            }
        }
        static int bTHeight(BTNode<ElemType>* target) {
            int lChildH,rChildH;
            if (target == nullptr) return 0;
            else {
                lChildH = bTHeight(target->lChild);
                rChildH = bTHeight(target->rChild);
                return (lChildH > rChildH) ? (lChildH + 1) : (rChildH + 1);
            }
        }
        static void display(BTNode<ElemType>* target) {
            using std::cout;
            using std::endl;
            if (target != nullptr) {
                cout << target->data;
                if (target->lChild != nullptr || target->rChild != nullptr) {
                    cout << "("; //有孩子节点输出“(”
                    display(target->lChild);
                    if (target->rChild != nullptr) cout << ",";//有右节点才会输出“,”
                    display(target->rChild);
                    cout << ")"; //有孩子节点输出“)”
                }
            }
        }
        static std::string toString(BTNode<ElemType>* target, std::string& last) {
            if (target != nullptr) {
                if (target->lChild != nullptr || target->rChild != nullptr) {
                    last += "("; //有孩子节点输出“(”
                    toString(target->lChild, last);
                    if (target->rChild != nullptr) last += ",";//有右节点才会输出“,”
                    toString(target->rChild, last);
                    last += ")"; //有孩子节点输出“)”
                }
            }
            return last;
        }
    };

    template<class ElemType>
    class BTTree {
        BTNode<ElemType>* root;
    public:
        /**
         * 对于list[]解释如下：<br/>
         * list[i] == nullptr 被认为仅是个占位符，不是待加元素 <br/>
         * 当且已加元素数 total == nodeTotal 时 不会再加元素 <br/>
         * 当 inx[i] == '\0'即退出遍历 <br/>
         * 对于inx[]解释如下：<br/>
         * inx[i] == '(' -> 在list[i],list[i+1]中插入'('操作 <br/>
         * inx[j] == ',' -> 在list[j],list[j+1]中插入','操作 <br/>
         * inx[p] == ')' -> 在list[p],list[p+1]中插入')'操作 <br/>
         * @param btTree
         * @param list
         * @param inx
         * @return 创建的二叉树指针
         */
        static BTTree* createBTTree(ElemType list[], const char inx[], int nodeTotal);
        void destroy();
        BTNode<ElemType>* findNode(ElemType target);
        BTNode<ElemType>* getRootNode();
        BTNode<ElemType>* getRootLChildNode();
        BTNode<ElemType>* getRootRChildNode();
        BTNode<ElemType>* getNodeLChildNode(BTNode<ElemType> *p);
        BTNode<ElemType>* getNodeRChildNode(BTNode<ElemType> *p);
        int getHeight();
        void display();
        std::string toString();
    };




} // ds

#endif //DADS_BTTREE_H
