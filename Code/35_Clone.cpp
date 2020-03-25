#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-35 题目：复杂链表的复制
        输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
    返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
思路：

 */
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
// 利用hash
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode *,RandomListNode *> m;
        RandomListNode *pTemp = pHead;
        // 创建值节点
        while(pTemp){
            m[pTemp] = new RandomListNode(pTemp->label);
            pTemp = pTemp->next;
        }
        // 拷贝next和random
        pTemp = pHead;
        while(pTemp){
            m[pTemp]->next = m[pTemp->next];
            m[pTemp]->random = m[pTemp->random];
            pTemp = pTemp->next;
        }
        return m[pHead];

    }
};

// 先穿成一个链表 再链表分离
class Solution1 {
public:
    // 先把节点克隆出来
    void CloneNode(RandomListNode *pHead){
        RandomListNode *pNode = pHead;
        while(pNode){
            RandomListNode *pTemp = new RandomListNode(pNode->label);
            pTemp->next = pNode->next;
            pNode->next = pTemp;
            pTemp->random = nullptr;

            pNode = pTemp->next;
        }
    }
    // 连接随机指针
    void ConnectRandom(RandomListNode *root){
        RandomListNode *pNode = root;
        while(pNode){
            if(pNode->random != nullptr){
                pNode->next->random = pNode->random->next;
            }
            pNode = pNode->next->next;
        }
    }
    // 将两个链表分离
    RandomListNode *depart(RandomListNode *root){
        RandomListNode *pTemp = root;
        RandomListNode *pHead = nullptr, *pNode = nullptr;
        if(pTemp){
            pHead = pNode = pTemp->next;
            pTemp->next = pHead->next;
            pTemp = pTemp->next;
        }
        while(pTemp){
            pNode->next = pTemp->next;
            pNode = pTemp->next;
            pTemp->next = pNode->next;
            pTemp = pTemp->next;
        }
        return pHead;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNode(pHead);
        ConnectRandom(pHead);
        return depart(pHead);
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}