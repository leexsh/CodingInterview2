#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-7 题目：重建二叉树
题目描述
    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。  
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/*
思路：

 */
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

// 剑指code
TreeNode *construct(int *preorder, int *inorder, int length){
    if(preorder == nullptr ||inorder == nullptr || length <= 0){
        return nullptr;
    }
    constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

TreeNode *constructCore(int *startPre, int *endPre, int *startIn, int *endIn){
    // 前序遍历的第一个节点 是头结点 先构造头节点
    int rootValue = startPre[0];
    TreeNode *root = new TreeNode(rootValue);
    // 只有一个节点 终止条件
    if(startPre == endPre){
        if(startIn == endIn && *startPre == *startIn){
            return root;
        }
    }
    // 在中序遍历中找到根节点
    int *pTemp = startIn;
    while(pTemp != endIn && *pTemp != rootValue){
        ++pTemp;
    }
    // 根节点的左子树的长度
    int leftLen = endIn - startIn;
    // 在前序遍历中确定左子树的位置
    int *leftPreEnd = startPre + leftLen;
    if(leftLen > 0){
        // 递归构建左子树
        root->left = constructCore(startPre + 1, leftPreEnd, startIn, pTemp - 1);
    }
    // 递归构建右子树
    if(leftLen < endPre - startPre){
        root->right = constructCore(leftPreEnd + 1, endPre, pTemp + 1, endIn);
    }
    return root;
}
// 牛客
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
// https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6?answerType=1&f=discussion
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0){
            return nullptr;
        }
        // 根节点
        int rootValue = pre[0];
        TreeNode *root = new TreeNode(rootValue);
        // 存放前中序遍历左右子树的数组
        vector<int> preLeft, preRight, inLeft, inRight;
        // 找根节点在中序中的位置
        int gen = 0;
        for(int i = 0; i < vin.size(); ++i){
            if(vin[i] == rootValue){
                gen = i;
                break;
            }
        }
        // 根据根节点的位置 确定左子树的节点数目
        for(int i = 0; i < gen; i++){
            inLeft.push_back(vin[i]);
            preLeft.push_back(pre[i+1]);
        }
        // 根据根节点的位置 确定右子树的节点数目
        for(int i = gen + 1; i < vin.size(); i++){
            inRight.push_back(vin[i]);
            preRight.push_back(pre[i]);
        }
    
        // 递归构建
        root->left = reConstructBinaryTree(preLeft, inLeft);
        root->right = reConstructBinaryTree(preRight, inRight);
        return root;
    }
   
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}
