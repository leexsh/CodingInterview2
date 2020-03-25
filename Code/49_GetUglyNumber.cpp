#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-49 题目：丑数
    把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，
    但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

/*
思路：

 */
// 过不了 超时了
class Solution {
public:
    bool isUblyNum(int num)
    {
        if(num == 1){
            return true;
        }
        bool f = true;
        while(num != 1)
        {
            if(num % 2 == 0){
                num /= 2;
            }
            else if(num % 3 == 0){
                num /= 3;
            }
            else if(num % 5 == 0){
                num /= 5;
            }
            else
            {
                f = false;
                break;
            }
        }
        return f;
    }
    int GetUglyNumber_Solution(int index) {
        if(index == 1){
            return 1;
        }
        int res = 0, i = 1;
        while(index)
        {   
            if(isUblyNum(i))
            {
                res = i;
                index--;
                i++;
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index < 7){
            return index;
        }
        vector<int> vec(index, 0);
        vec[1] = 0;
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1;i < index; i++)
        {
            vec[i] = min(vec[p2] * 2, min(vec[p3] * 3, vec[p5] * 5));
            if(vec[i] == vec[p2] * 2){p2++;}
            if(vec[i] == vec[p3] * 3){p3++;}
            if(vec[i] == vec[p5] * 5){p5++;}
        }
        return vec[index - 1];
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    Solution s;
    int x = s.GetUglyNumber_Solution(4);
    cout<<x<<endl;
    system("pause");
    return 0;
}