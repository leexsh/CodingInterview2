#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-23 题目：链表中环的入口结点
    给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。  
*/

/*
思路：

 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};
class Solution {
public:

    // 判断链表是否有环
    // 指针一块一慢 相遇则有环
    ListNode *isLoop(ListNode *pHead){
        if(pHead == nullptr){
            return nullptr;
        }
        // 慢指针
        ListNode *pSlow = pHead->next;
        if(pSlow == nullptr){
            return nullptr;
        }
        // 快指针
        ListNode *pFast = pSlow->next;
        while(pFast && pSlow){
            // 相遇
            if(pFast == pSlow){
                return pFast;
            }
            // 慢指针走一步 快指针走两步
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr){
                pFast = pFast->next;
            }
        }
        // 不是有环链表
        return nullptr;
    }
    // 找到有环链表中的入口结点
    // 快指针先走环的长度 慢指针和快指针一起走 最后会在入口处相遇
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr){
            return nullptr;
        }
        // 判断是否有环
        ListNode *pNode = isLoop(pHead);
        if(pNode == nullptr){
            // 无环
            return nullptr;
        }
        // 有环 继续走
        // 环的长度
        int num = 1;
        ListNode *pTemp = pNode->next;
        // 计算环的长度
        while(pTemp != pNode){
            num++;
            pTemp = pTemp->next;
        }
        // 快指针 先走 环的长度
        ListNode *pFast = pHead;
        while(num){
            pFast = pFast->next;
            num--;
        }
        // 慢指针
        ListNode *pSlow = pHead;
        // 快慢指针一起走
        while(pSlow != pFast){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        // 返回环的入口结点
        return pFast;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}