#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-18_1 题目：删除链表中的重复元素
    在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
    返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
思路：

 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){

    }
};

// C语言版本 剑指offer
class Solution {
public:
    void deleteDuplication(ListNode** pHead)
    {
       if(*pHead == nullptr || pHead == nullptr){
           return;
       }
        // 被删除节点的前一个节点
       ListNode *preNode = nullptr;
       
       ListNode *pNode = *pHead;
       while(pNode){
            ListNode *pNext = pNode->next;
            bool delFlag = false;
            //    发现相同元素
            if(pNext != nullptr && pNode->val == pNext->val){
               delFlag = true;
            }
            //    如果没有相同元素 继续向下走
            if(delFlag == false){
                preNode = pNode;
                pNode = pNode->next;
            }
            else
            {
                // 有重复的元素 挨个删除
                int value = pNode->val;
                ListNode *pDel = pNode;
                while(pDel != nullptr && pDel->val == value){
                    pNext = pDel->next;
                    delete pDel;
                    pDel = nullptr;

                    pDel = pNext;
                }
                if(preNode == nullptr){
                    preNode = pNext;
                }
                else
                {
                    preNode->next = pNext;
                }
                pNode = pNext;
            }
       }
    }
};

// C++版本
class Solution1 {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        // 创造一个头结点
        ListNode *preNode = new ListNode(-1);
        preNode->next = pHead;
        // 被删除节点的前一个
        ListNode *pre = preNode;
        ListNode *pNode = pHead;
        while(pNode){
            // 删除所有的重复节点
            if(pNode->next != nullptr && pNode->val == pNode->next->val){
                while(pNode->next != nullptr && pNode->next->val == pNode->val){
                    ListNode *pDel = pNode;
                    pNode = pNode->next;
                    delete pDel;
                    pDel = pDel->next;
                }
                pre->next = pNode->next;
                pNode = pNode->next;
            }
            // 没有重复
            else{
                pre = pre->next;
                pNode = pNode->next;
            }
            
        }
        return preNode->next;
    }
};

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}