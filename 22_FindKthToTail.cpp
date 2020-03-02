#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-22 链表中的倒数第k个节点 题目：
输入一个链表，输出该链表中倒数第k个结点
*/

/*
思路：

 */
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int value):val(value), next(nullptr){}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k <= 0){
            return nullptr;
        }
        ListNode *pFast = pListHead;
        while(k > 0){
            // 不够k个节点
            if(pFast == nullptr){
                return nullptr;
            }
            else
            {
                pFast = pFast->next;
            }
            k--;
        }
        // 快指针走到头 慢指针走到倒数k个节点
        ListNode *pSlow = pListHead;
        while(pFast != nullptr){
            pFast = pFast->next;
            pSlow = pSlow->next;
        }
        return pSlow;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}