#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-27 题目：二叉树的镜像
    题目描述
        操作给定的二叉树，将其变换为源二叉树的镜像。
    输入描述:

        二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11

    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
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

// 递归方法
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == nullptr){
            return ;
        }
        if(pRoot->left == nullptr && pRoot->right == nullptr){
            return ;
        }

        TreeNode *pTemp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTemp;

        if(pRoot->left){
            Mirror(pRoot->left);
        }
        if(pRoot->right){
            Mirror(pRoot->right);
        }
    }
};

// 非递归 类似于层次遍历
class Solution1 {
public:
    void Mirror(TreeNode *pRoot) {
        // 肯定不会是镜像
        if(pRoot == nullptr){
            return ;
        }
        if(pRoot->left == nullptr && pRoot->right == nullptr){
            return ;
        }
        TreeNode *pNode;
        // 栈
        stack<TreeNode*> st;
        st.push(pRoot);
        while(!st.empty()){
            pNode = st.top();
            st.pop();
            // 先交换一个
            if(pNode->left != nullptr || pNode->right != nullptr){
                TreeNode *pTemp = pNode->left;
                pNode->left = pNode->right;
                pNode->right = pTemp;
            }
            // 再递归交换
            if(pNode->left){
                st.push(pNode->left);
            }
            if(pNode->right){
                st.push(pNode->right);
            }
            
        }
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}