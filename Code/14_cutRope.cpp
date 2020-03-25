#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-15 题目：剪绳子
    题目描述    
        给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
    输入描述:
        输入一个数n，意义见题面。（2 <= n <= 60）
    输出描述:
        输出答案。
    示例1 
        输入
            8
        输出
            18
*/

/*
思路：
    
 */
// 1.动态规划
class Solution {
public:
    int cutRope(int number) {
        if(number <= 1){
            return 0;
        }
        if(number == 2){
            return 1;
        }
        if(number == 3){
            return 2;
        }
        vector<int> vec(number + 1, 0);
        // 记录最大
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        vec[3] = 3;
        // int max = 0;
        for(int i = 4; i <= number;i++){
            for(int j = 1; j <= i/2; j++){
                if(vec[j] * vec[i - j] > vec[i]){
                    vec[i] = vec[j] * vec[i - j];
                }
                // vec[i] = max;
            }
        }

        return vec[number];
    }
};

// 贪心 如果大于3 就减掉3 如果不够3  就减掉2
class Solution2 {
public:
    int cutRope(int number) {
        if(number <= 1){
            return 0;
        }
        if(number == 2){
            return 1;
        }
        if(number == 3){
            return 2;
        }
        int timeof3 = number / 3;
        if(number - timeof3 * 3 == 1){
            timeof3 -= 1;
        }   
        int timeof2 = (number - timeof3 * 3)/2;
        return int(pow(3,timeof3)) * int(pow(2,timeof2)); 
    }
};
class Solution3 {
public:
    int cutRope(int number) {
        if(number <= 1){
            return 0;
        }
        if(number == 2){
            return 1;
        }
        if(number == 3){
            return 2;
        }
        if(number % 3 == 0){
            return pow(3,number/3);
        } 
        else if(number % 3 == 1){
            return pow(3, number/3 - 1) * 4;
        }
        else
        {
            return 2 * pow(3,number);
        }
        
    }
};


int main(){
    // Solution4 s;
    // int x = s.cuttingRope(2);
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}