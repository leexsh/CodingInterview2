#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-42 题目：连续子数组的最大和

*/

/*
思路：

 */
class Solution {
public:
    int FindGreatestSumOfSubArray1(vector<int> array) {
        int maxsum = INT_MIN;
        int size = array.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                int tersum = 0;
                for(int k = i; k <= j; k++){
                    tersum += array[k];
                }
                if(maxsum < tersum){
                    maxsum = tersum;
                }
            }
        }
        return maxsum;
    }

    int FindGreatestSumOfSubArray2(vector<int> array){
        int sum = array[0];
        int maxnum = array[0];
        for(int i = 1; i < array.size(); i++){
            sum = max(sum + array[i], array[i]);
            maxnum = max(maxnum, sum);
        }
        return maxnum;
    }
};
int main(){


    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}