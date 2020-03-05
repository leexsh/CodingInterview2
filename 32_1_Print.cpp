#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-32-1 题目：把二叉树打印成多行
    从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> vec;
        if(pRoot == nullptr){
            return vec;
        }    
        deque<TreeNode*> que;
        que.push_back(pRoot);
        while(!que.empty()){
            vector<int> v;
            int n = que.size();
            while(n--){
                TreeNode *pNode = que.front();
                v.push_back(pNode->val);
                if(pNode->left){
                    que.push_back(pNode->left);
                }
                if(pNode->right){   
                    que.push_back(pNode->right);
                }
                que.pop_front();
            }
            vec.push_back(v);
            
        }
        return vec;

    }
    
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}