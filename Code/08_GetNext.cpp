#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-8 题目：二叉树的下一个节点
    给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
    注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/*
思路：
    找前驱和找后继
 */
class TreeLinkNode {
public:
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};
// 找后继 分两种情况：
// 该节点有右子树的话  他的后继节点是右子树上最左的节点
// 没有右子树 一直往上找 找到某一个节点是其父节点的左孩子为止 那么他的后继节点就是这个父节点
TreeLinkNode *getNext(TreeLinkNode *pNode){
    if(pNode == nullptr){
        return nullptr;
    }
    // 有右孩子
    if(pNode->right){
        pNode = pNode->right;
        while(pNode->left){
            pNode = pNode->left;
        }
        return pNode;
    }
    // 没有右孩子
    else
    {
        TreeLinkNode *parent = pNode->next;
        while(parent != nullptr && parent->left != pNode){
            pNode = parent;
            parent = parent->next;
        }
        return parent;
    }
}

// 找前驱
// 找前驱跟找后继类似
// 如果有左孩子 就是左孩子上最右的节点
// 没有左孩子 就往上找 一直找到某个节点是父节点的右孩子 那么父节点就是后继节点
TreeLinkNode *getPre(TreeLinkNode *pNode){
    if(pNode == nullptr){
        return nullptr;
    }
    if(pNode->left){
        pNode = pNode->left;
        while(pNode->right){
            pNode = pNode->right;
        }
        return pNode;
    }else
    {
        TreeLinkNode *parent = pNode->next;
        while(parent != nullptr && parent->right != pNode){
            pNode = parent;
            parent = parent->next;
        }
        return parent;
    }
}

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}