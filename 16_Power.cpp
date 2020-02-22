#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-16 题目：数值的整数次方

*/

/*
思路：

 */
// 非递归
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0){
            return 0;
        }
        double res = -1;
        int absExpon = exponent > 0 ? exponent : -exponent;
        for(int i = 1;i < absExpon; i++){
            res *= base;
        }
        if(exponent < 0){
            res = 1.0 / res;
        }
        return res;
    }
};
// 递归
class Solution1{
public:
    double Power(double base, int exponent) {
        int n = abs(exponent);
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return base;
        }
        double res = 1.0;
        res = Power(base, n>>1);
        res *= res;
        if(n & 1 )
        {
            res *= base;
        }
        return exponent > 0 ? res :1.0/res;
    }
};

// 快速幂
class Solution2{
public:
    double Power(double base, int exponent) {
        int n = abs(exponent);
        double res = 1.0;
        while(n){
            if(n & 1){
                res *= base;
            }
            base *= base;
            n >>= 1;
        }
        return exponent > 0 ? res :1.0/res;
    }
};
int main(){
    Solution1 s;
    s.Power(2,3);
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}