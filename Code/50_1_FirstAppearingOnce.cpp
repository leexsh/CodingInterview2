#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-50-1 题目：字符流中第一个不重复的字符

*/

/*
思路：
    
 */
class Solution
{
public:
    map<char, int> m;
    vector<int> vec;
  //Insert one char from stringstream
    void Insert(char ch)
    {
         m[ch]++;
         vec.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i = 0; i < vec.size(); ++i)
        {
            if(m[vec[i]] == 1)
            {
                return vec[i];
            }
        }
        return '#';
    }

};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}