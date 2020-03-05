#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-32 题目：从上向下打印二叉树
    从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vec;
        if(root == nullptr){
            return vec;
        }
        deque<TreeNode*> que;
        que.push_back(root);
        while(!que.empty()){
            TreeNode *pNode = que.front();
            que.pop_front();
            vec.push_back(pNode->val);
            if(pNode->left){
                que.push_back(pNode->left);
            }
            if(pNode->right){
                que.push_back(pNode->right);
            }
        }
        return vec;

    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}