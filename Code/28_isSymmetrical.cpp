#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-28 题目：对称的二叉树
    请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

/*
思路：

 */
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int v):val(v), left(nullptr), right(nullptr){}
};

// 递归
class Solution {
public:
    bool coreDeal(TreeNode *p1, TreeNode *p2){
        if(p1 ==nullptr && p2 == nullptr){
            return true;
        }
        if(p1 == nullptr || p2 == nullptr)
        {
            return false;
        }
        if(p1->val != p2->val){
            return false;
        }
        // 左子树的左子树和右子树的右子树比较   左子树的右子树和右子树的左子树比较
        return coreDeal(p1->left, p2->right)&&coreDeal(p1->right, p2->left);
        

    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        return coreDeal(pRoot,pRoot);
    }

};

// 非递归
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        // pRoot == nullptr return true
        if(pRoot == nullptr){
            return true;
        }
        stack<TreeNode *> st;
        st.push(pRoot->left);
        st.push(pRoot->right);
        
        while(!st.empty()){
            // 成对拿出
            
            TreeNode *right = st.top();
            st.pop();
            TreeNode *left = st.top();
            st.pop();
            if(right == nullptr && left == nullptr){
                continue;
            }
            if(right == nullptr || left == nullptr){
                return false;
            }
            if(right->val != left->val){
                return false;
            }
           
            
            // 成对放入
            st.push(left->left);
            st.push(right->right);
            
            st.push(left->right);
            st.push(right->left);
        }
        return true;
    }

};

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}