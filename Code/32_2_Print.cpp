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
        stack<TreeNode*> s1, s2;
        int hang = 1;
        s1.push(pRoot);
        while(!s1.empty() || !s2.empty())
        {
            TreeNode *pNode;
            vector<int> v;
            int n;
            // 奇数的行
            if(hang % 2 == 1){
                n = s1.size();
                while(n--){
                    pNode = s1.top();
                    v.push_back(pNode->val);
                    if(pNode->left){
                        s2.push(pNode->left);
                    }
                    if(pNode->right){
                        s2.push(pNode->right);
                    }
                    s1.pop();
                }
                hang++;
                vec.push_back(v);
            }
            // 偶数的行
            else
            {
                n = s2.size();
                while(n--){
                    pNode = s2.top();
                    v.push_back(pNode->val);
                    if(pNode->right){
                        s1.push(pNode->right);
                    }
                    if(pNode->left){
                        s1.push(pNode->left);
                    }
                    
                    s2.pop();
                }
                hang++;
                vec.push_back(v);
            }
            
        }
        return vec;
    }
    
};
int main(){

    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> v = s.Print(p);
    for(auto i = 0; i < v.size(); i++){
        for(auto j = 0; j < v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
    }
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}