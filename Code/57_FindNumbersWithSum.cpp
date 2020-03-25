#include "bits/stdc++.h"
#include <limits>
using namespace std;
/* 
剑指offer-57 题目：和为S的两个数字

*/

/*
思路：
    a b越远乘积越小
 */

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> vec;
        int i = 0, j = array.size()- 1;
        int res = 2147483647;
        while(i < j)
        {
            int ss = array[i] + array[j];
            if(ss == sum)
            {       
                vec.push_back(array[i]);
                vec.push_back(array[j]);
                break;
            }
            else if(ss < sum)
            {
                i++;
            }
            else if(ss > sum)
            {
                j--;
            }
        }  
        return vec;    
    }
};
int main(){
    vector<int> vec{1,2,4,7,8,11,15};
    Solution s;
    vector<int> ss = s.FindNumbersWithSum(vec,15);
    for(auto i : ss){
        cout<<i<<" ";
    }
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}