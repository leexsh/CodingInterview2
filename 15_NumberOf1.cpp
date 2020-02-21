#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-15 题目：二进制中1的个数
    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

/*
思路：
    
 */

// 方法一：flag从右边开始 每次都与n进行与运算 如果位数都是1 那么就count++ flag每次都要右移 和n的每一位进行运算
// 这样的话 有多少位 就进行多少次运算
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         unsigned int flag = 1;
         while(flag){
             if(n & flag){
                 count++;
             }
             flag = flag << 1;
         }
         return count;
     }
};
// 方法2 n-1就是使得 n中的最右边的1变为0 
class Solution1 {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n){
             count++;
             n = (n-1)&n;
         }
         return count;
     }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}


