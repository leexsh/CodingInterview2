#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer- 题目：

*/

/*
思路：

 */

class Solution {
public:    
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {        
        if(pushV.empty()){
            return false;
        }
        stack<int> s;
        int i = 0, j = 0;
        while(i != pushV.size()){
            s.push(pushV[i]);
            while(j != popV.size() && popV[j] == s.top())
            {
                s.pop();
                j++;
            }
            ++i;
        }
        return s.empty();
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}