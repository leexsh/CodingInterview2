#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-55 题目：二叉树的深度
    输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
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
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr){
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return max(left, right) + 1;
    }
};

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}