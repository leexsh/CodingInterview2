#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-21 题目：调整数组顺序使奇数位于偶数前面
    题目描述
    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
    所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*
思路：

 */

// 不考虑顺序
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty()){
            return;
        }
        int start = 0; 
        int end = array.size() - 1;
        while(start < end)
        {
            while(((array[start] & 0x01) != 0) && start < end){
                start++;
            }
            while((array[end] & 0x01) == 0 && start < end){
                end--;
            }
            if(start != end){
                int temp = array[start];
                array[start] = array[end];
                array[end] = temp;
            }

        }
    }
};

// 考虑相对顺序

bool core(int n){
        return ((n & 1) == 1);
}
class Solution {
public:
  
    void reOrderArray(vector<int> &array) {
        stable_partition(array.begin(), array.end(),core);

    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}