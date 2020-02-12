#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-10 题目：斐波那契数列
    大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。 n<=39 
*/

/*
思路：
    1.递归
    2.非递归
 */
// 递归 时间复杂度过大
class Solution1 {
public:
    int Fibonacci(int n) {
        if(n <= 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};

// 非递归
class Solution2 {
public:
    
    int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int  a = 0, b = 1, c = 0;
        for(int i = 2; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
class Solution {
public:
    int jumpFloor(int number) { 
        if(number <= 1){
            return number;
        }
        int a = 1, b = 1, c = 0;
        for(int i = 2; i<= number; i++){
            c = a + b;
            a = b;
            b = c;
        }
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}