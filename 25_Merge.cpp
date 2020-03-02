#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-25 题目：合并两个有序链表
    输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
思路：

 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

// 递归过程
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr){
            return pHead2;
        }
        if(pHead2 == nullptr){
            return pHead1;
        }
        ListNode *pMergeHead = nullptr;
        if(pHead1->val < pHead2->val){
            pMergeHead = pHead1;
            pMergeHead->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            pMergeHead = pHead2;
            pMergeHead->next = Merge(pHead1, pHead2->next);
        }
        return pMergeHead;
    }
};

// 非递归过程 就是个Merge的过程
class Solution1 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *pHead = new ListNode(-1);
        pHead->next = nullptr;
        ListNode *pNode = pHead;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                pNode->next = pHead1;
                pHead1 = pHead1->next;
                pNode = pNode->next;
            }
            else
            {
                /* code */
                pNode->next = pHead2;
                pHead2 = pHead2->next;
                pNode = pNode->next;
            }
        }    
        if(pHead1){
            pNode->next = pHead1;
        } 
        if(pHead2){
            pNode->next = pHead2;
        }
        return pHead->next;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}