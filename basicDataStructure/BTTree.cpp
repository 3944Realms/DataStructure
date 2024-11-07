//
// Created by f2561 on 24-10-31.
//

#include "BTTree.h"
#include "LinkedStack.h"

namespace ds {
    template<class ElemType>
    ds::BTTree<ElemType> *BTTree<ElemType>::createBTTree(ElemType list[], const char inx[], int nodeTotal) {//规定下基本类型下各个分割字符
        auto* ret = new BTTree<ElemType>();
        ret->root = nullptr; // 初始化根节点为 nullptr
        BTNode<ElemType>* pBtNode = nullptr; // 当前节点
//        BTNode<ElemType>* p = nullptr; // 额外指针
        ds::LinkedStack<ElemType> nodeStack; // 用于管理节点的栈
        int total = 0; // 当前添加的节点数
        int i = 0; // 用于遍历 list
        int j = 0; // 用于遍历 inx
        char ch;

        while ((ch = inx[j++]) != '\0' && total < nodeTotal) {
            // 跳过空占位符
            while (list[i] == nullptr) {
                i++;
            }
            // 创建当前节点
            pBtNode = new BTNode<ElemType>{list[i++], nullptr, nullptr};
            total++;

            switch (ch) { // NOLINT(*-multiway-paths-covered)
                case '(': // 左括号表示进入左子树
                    if (ret->root == nullptr) {
                        ret->root = pBtNode; // 设置根节点
                    } else {
                        // 检查栈顶节点的左子节点是否为空
                        if (nodeStack.top()->lChild == nullptr) {
                            nodeStack.top()->lChild = pBtNode; // 连接为左子节点
                        } else {
                            // 如果左子节点已经存在，连接为右子节点
                            nodeStack.top()->rChild = pBtNode;
                        }
                    }
                    nodeStack.push(pBtNode); // 入栈当前节点
                    break;
                case ')': // 右括号表示回到父节点
                    if (!nodeStack.empty()) {
                        nodeStack.pop(); // 弹出栈顶节点
                    }
                    break;
                case ',': // 逗号表示当前节点完成，准备下一个节点
                    if (!nodeStack.empty()) {
                        nodeStack.top()->rChild = pBtNode; // 连接为右子节点
                    }
                    break;
            }
        }
        return ret; // 返回创建的树
    }


    template<class ElemType>
    void ds::BTTree<ElemType>::destroy() {
        if (this->root != nullptr)
            this->root->destroy();
    }

    template<class ElemType>
    BTNode<ElemType>* ds::BTTree<ElemType>::findNode(ElemType target) {
        return this->findNode(target);
    }

    template<class ElemType>
    BTNode<ElemType> *BTTree<ElemType>::getRootNode() {
        return this->root;
    }

    template<class ElemType>
    BTNode<ElemType>* ds::BTTree<ElemType>::getRootLChildNode() {
        return this->root->lChild;
    }

    template<class ElemType>
    BTNode<ElemType>* ds::BTTree<ElemType>::getRootRChildNode() {
        return this->root->rChild;
    }

    template<class ElemType>
    BTNode<ElemType> *BTTree<ElemType>::getNodeLChildNode(BTNode<ElemType> *p) {
        return p->lChild;
    }

    template<class ElemType>
    BTNode<ElemType> *BTTree<ElemType>::getNodeRChildNode(BTNode<ElemType> *p) {
        return p->rChild;
    }

    template<class ElemType>
    int ds::BTTree<ElemType>::getHeight() {
        return BTNode<ElemType>::bTHeight(this->root);
    }

    template<class ElemType>
    void ds::BTTree<ElemType>::display() {
        BTNode<ElemType>::display(this->root);
    }

    template<class ElemType>
    std::string ds::BTTree<ElemType>::toString() {
        std::string ret;
        return BTNode<ElemType>::toString(this->root, ret);
    }

} // ds