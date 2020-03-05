#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-26 题目：树的子结构
    输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

/*
思路：  
    递归
 */
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int v):val(v), left(nullptr), right(nullptr){}
};

class Solution {
public: 
    bool Equal(double num1, double num2){
        if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001)){
            return true;
        }
        return false;
    }
    
    // 核心处理 挨个节点判断是否相等
    bool coreDeal(TreeNode* pRoot1, TreeNode* pRoot2){
        // 待匹配为空 返回true
        if(pRoot2 == nullptr){
            return true;
        }
        // 匹配为空 返回false
        if(pRoot1 == nullptr){
            return false;
        }

        // 根节点相等
        if(Equal(pRoot1->val, pRoot2->val)){
            return coreDeal(pRoot1->left, pRoot2->left) && coreDeal(pRoot1->right, pRoot2->right);
        }
        else
        {
            return false;
        }
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        
        bool flag = false;
        // 都不空
        if(pRoot1 != nullptr && pRoot2 != nullptr){
            // 根节点匹配了
            if(Equal(pRoot1->val, pRoot2->val)){
                flag = coreDeal(pRoot1, pRoot2);
            }   
            // 跟不匹配 匹配左子树
            if(flag == false){
                flag = coreDeal(pRoot1->left, pRoot2);
            }
            // 左子树不匹配 匹配右子树
            if(flag == false){
                flag = coreDeal(pRoot1->right, pRoot2);
            }
        }
        return flag;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}