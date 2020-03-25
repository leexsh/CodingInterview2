#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-43 题目：1-n整数中1出现的次数

*/

/*
思路：

 */
class Solution {
public:
    int core(int n){
        int ans = 0;
        while(n != 0){
            if(n % 10 == 1){
                ans++;
            }
            n /= 10;
        }
        return ans;
    }
    int NumberOf1Between1AndN_Solution(int n)
    {   
        if(n <= 0){
            return 0;
        }
        int count = 1;
        for(int i = 2; i <= n; i++){
            count += core(i);
        }
        return count;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}