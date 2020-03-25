#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-52 题目：相交链表中的第一个节点
    输入两个链表，找出它们的第一个公共结点。
    （注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
*/

/*
思路：
    快先走 一起走
 */
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr || pHead2 == nullptr){
            return nullptr;
        }
        int len1 = 0;
        int len2 = 0;
        ListNode *pNode = pHead1;
        while(pNode){
            len1++;
            pNode = pNode->next;
        }
        pNode = pHead2;
        while(pNode){
            len2++;
            pNode = pNode->next;
        }
        ListNode *pTemp = nullptr;
        int num = len1 > len2 ? len1 - len2 : len2 - len1;
        if(len1 > len2){
            pNode = pHead1;
            while(num--){
                pNode = pNode->next;
            }
            pTemp = pHead2;
        }else
        {
            pNode = pHead2;
            while(num--){
                pNode = pNode->next;
            }
            pTemp = pHead1;
        }
        while(pTemp != pNode){
            pTemp = pTemp->next;
            pNode = pNode->next;
        }
        return pNode;
    }
};

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}