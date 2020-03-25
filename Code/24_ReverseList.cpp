#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-24 题目：翻转链表
    输入一个链表，反转链表后，输出新链表的表头
*/

/*
思路：

 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};
// 非递归
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        // 新的头结点
        ListNode *pNewHead = nullptr;
        // 遍历节点
        ListNode *pNode = pHead;
        // 翻转的节点
        ListNode *pPre = nullptr;
        while (pNode)
        {
            /* code */
            if(pNode->next == nullptr){
                pNewHead = pNode;
            }
            ListNode *pNext = pNode->next;
            pNode->next = pPre;
            pPre = pNode;
            pNode = pNext;
        }
        return pNewHead;
        
    }
};

// 递归
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        ListNode *pRev = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;

        return pRev;
    }
};

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}