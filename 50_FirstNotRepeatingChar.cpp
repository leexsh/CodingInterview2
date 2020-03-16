#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-50 题目：第一个只出现一次的字符
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）

*/

/*
思路：

 */

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> m;
        if(str.empty()){
            return -1;
        }
        for(auto i: str){
            m[i]++;
        }
        for(auto i = 0; i < str.size(); i++)
        {
            if(m[str[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
int main(){ 
    
    // cout<<"iii   ii"<<endl; 
    system("pause");
    return 0;
}