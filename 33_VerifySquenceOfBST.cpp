#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-33 题目：二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

*/

/*
思路：

 */


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 条件判断
        if(sequence.empty()){
            return false;
        }
        int i = 0;
        int num = sequence[sequence.size() - 1];
        // 找到左子树最后一个
        vector<int> leftVec, rightVec;
        for(i; i < sequence.size()-1; ++i){
            if(sequence[i] > num){
                break;
            }
            // 加入到左子树集合
            leftVec.push_back(sequence[i]);
        }
        // 右子树加入集合
        int j = i;
        for(j; j < sequence.size() - 1;++j){
            if(sequence[j] < num){
                return false;
            }
            rightVec.push_back(sequence[j]);
        }
        // 递归
        bool leftFlag = true;
        if(i > 0){
            leftFlag = VerifySquenceOfBST(leftVec);
        }
        bool rightFlag = true;
        if(j < sequence.size() - 1){
            rightFlag = VerifySquenceOfBST(rightVec);
        }

        return (leftFlag && rightFlag);
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}