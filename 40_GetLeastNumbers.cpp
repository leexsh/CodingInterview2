#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-40 题目：数组中最小的k个数

*/

/*
思路：

 */



class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> vec;
        priority_queue<int> que;
        if(k <= 0 || input.size() < k){
            return vec;
        }
        for(int i = 0; i < input.size(); ++i){
            if(que.size() < k){
                que.push(input[i]);
            }
            else
            {
                if(input[i] < que.top()){
                    que.pop();
                    que.push(input[i]);
                }
            }
        }
        while(!que.empty()){
            vec.push_back(que.top());
            que.pop();
        }
        return vec;
    }

};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}