#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-18 题目：删除链表的节点
    在O(1)的复杂度下 删除某个节点
*/

/*
思路：

 */

struct ListNode{
    
    int m_nValue;
    ListNode *m_pNext;

    ListNode(int value) : m_nValue(value), m_pNext(nullptr){}
};

void DeleteNode(ListNode **pListNode, ListNode *pToDel){
    if(*pListNode == nullptr || pToDel == nullptr){
        return;
    }
    
    // 删除的不是尾结点 把删除节点的下一节点移到删除节点  删除下一个节点
    if(pToDel->m_pNext != nullptr){
        pToDel->m_nValue = pToDel->m_pNext->m_nValue;
        ListNode *pTemp = pToDel->m_pNext;
        pToDel->m_pNext = pTemp->m_pNext;

        delete pTemp;
        pTemp = nullptr;
    }

    // 链表中只有一个节点 直接删除
    else if(*pListNode == pToDel){

        delete pToDel;
        pToDel = nullptr;
        *pListNode = nullptr;
    }

    // 删除的是尾结点 从头结点开始遍历 找到删除节点的前一个节点 
    else if(pToDel == nullptr)
    {
        /* code */
        ListNode *pTemp = *pListNode;
        while(pTemp->m_pNext != pToDel){
            pTemp = pTemp->m_pNext;
        }
        pTemp->m_pNext = nullptr;
        delete pToDel;
        pToDel = nullptr;
    }
}

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}