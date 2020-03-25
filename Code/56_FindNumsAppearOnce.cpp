#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-55 题目：数组中只出现一次的数字
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。    
*/

/*
思路：

 */

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        set<int> s1;
        for(auto i : data){
            if(s1.count(i)){
                s1.erase(i);
            }
            else{
                s1.insert(i);            
            }
        }
        auto ite1 = s1.begin();
        *num1 = *ite1;
        s1.erase(ite1);
        ite1 = s1.begin();
        *num2 = *ite1;
    }
};
int main(){
    vector<int> v{2,4,3,6,3,2,5,5};
    int *num1, *num2;
    Solution s;
    s.FindNumsAppearOnce(v, num1, num2);
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}