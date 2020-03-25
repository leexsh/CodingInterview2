#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-39 题目：数组中出现次数超过一半的数字

*/

/*
思路：

 */
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int num = numbers[numbers.size() / 2];
        int count = 0;
        for(auto i: numbers){
            if(i == num)
                count++;
        }
        // return numbers[numbers.size() / 2];
        return count > numbers.size() / 2 ? numbers[numbers.size()/ 2] : 0;
    }
};
class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()){
            return 0;
        }
        int result = numbers[0];
        int times = 1;
        for(auto i : numbers){
            if(times == 0){
                result = i;
                times = 1;
            }
            else if(i == result)
            {
                times++;
            }
            else
            {
                times--;
            }
        }
        int count = 0;
        for(auto i : numbers){
            if(i == result)
            {
                count++;
            }
        }
        return count > numbers.size() / 2 ? result : 0;

    }
};

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}