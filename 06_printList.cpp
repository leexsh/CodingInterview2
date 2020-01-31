#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-6 题目：从尾到头、、打印链表
    输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

/*
思路：

 */
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
// 递归翻转链表
class Solution1 {
public:
    vector<int> vec;
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head){
            if(head->next){
                printListFromTailToHead(head->next);
            }
            vec.push_back(head->val);
        }
        return vec;
    }
};
// 利用栈翻转链表
class Solution2 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        while(head){
            s.push(head->val);
            head = head->next;
        }
        vector<int> vec;
        while(!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
        return vec;
    }
};
// 链表尾添加节点
void AddToTail(ListNode **pHead, int value){
    ListNode *pNew = new ListNode(value);
    if(*pHead == nullptr){
        *pHead = pNew;
    }
    else
    {
        /* code */
        ListNode *pTemp = *pHead;
        while (pTemp->next != nullptr)
        {
            /* code */
            pTemp = pTemp->next;
        }
        pTemp->next =  pNew;
        
    }
    
}
// 删除链表中某一个值
void delNode(ListNode **pHead, int value){
    if(pHead == nullptr || *pHead == nullptr){
        return;
    }
    ListNode *pDel = nullptr;
    // 删除表头
    if((*pHead)->val == value){
        pDel = *pHead;
        (*pHead) = (*pHead)->next;
    }
    else
    {   
        ListNode *pTemp = *pHead;
        while(pTemp->next != nullptr && pTemp->next->val != value){
            pTemp = pTemp->next;
        }
        if(pTemp->next != nullptr && pTemp->next->val == value){
            pDel = pTemp->next;
            pTemp->next = pTemp->next->next;
        }
    }
    if(pDel != nullptr){
        delete pDel;
        pDel = nullptr;
    }
}
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}