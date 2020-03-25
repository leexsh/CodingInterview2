#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-57 题目：和为S的连续正数序列

*/

/*
思路：

 */
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> vec;
        if(sum < 3){
            return vec;
        }
        int big = 2;
        int small = 1;
        // 终止条件
        int mid = (sum + 1)/2;
        int curSum = big + small;
        while(small < mid)
        {
            vector<int> temp;
            if(curSum == sum)
            {
                for(int i = small; i <= big; i++)
                {
                    temp.push_back(i);
                }
                vec.push_back(temp);
                temp.clear();
            }
            while(small < mid && curSum > sum)
            {
                curSum -= small;
                small++;
                if(curSum == sum){
                    for(int i = small; i <= big; i++)
                    {
                        temp.push_back(i);
                    }
                    vec.push_back(temp);
                    temp.clear();

                }
               
            }
            big++;
            curSum += big;
        }
        return vec;
    }
};


class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> vec;
        if(sum < 3){
            return vec;
        }
        int small = 1;
        int big = 2;
        while(big > small){
            // 等差数列求和
            int curSum = (small + big)*(big - small + 1)/2;
            if(curSum == sum)
            {
                vector<int> temp;
                for(int i = small; i <= big; i++)
                {
                    temp.push_back(i);
                }
                vec.push_back(temp);
                big++;
            }
            else if(curSum < sum)
            {
                /* code */
                big++;
            }
            else
            {
                small++;
            }
        }
        return vec;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}