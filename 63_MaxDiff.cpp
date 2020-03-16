#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer- 题目：

*/

/*
思路：

 */
// 笨办法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() < 2){
            return 0;
        }
        int max = 0;
        int size = prices.size();
        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1; j < size; j++ )
            {   
                if(prices[j] - prices[i] > max)
                {
                    max = prices[j] - prices[i];
                }
            }
        }
        return max;
    }
};

// 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size() < 2){
            return 0;
        }
        int min = prices[0];
        int maxdiff = prices[1] - min > 0 ? prices[1] - min : 0;
        for(auto i  = 2;i < prices.size(); i++)
        {
            if(prices[i-1] < min){
                min = prices[i - 1];
            }
            int curdiff = prices[i] - min;
            if(curdiff > maxdiff)
                maxdiff = curdiff;
        }
        return maxdiff;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}