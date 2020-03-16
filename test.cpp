#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer- 题目：

*/

/*
思路：

 */
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}

class Solution {
public:
    int find(vector<int> &nums, int left, int right)
    {
        int min = nums[left];
        for(int i = left; i <= right; i++)
        {
            if(nums[i] < nums[left]){
                min = nums[i];
            }
        }
        return min;
    }
    int minArray(vector<int>& numbers) {
        if(numbers.size() == 1){
            return numbers[0];
        }
        int low = 0;
        int high = numbers.size() - 1;
        int mid = 0;
        while(numbers[low] >= numbers[high])
        {
            mid = low + (high - low) / 2;
            if(numbers[low] == numbers[mid] && numbers[high] == numbers[mid])
            {   
                return find(numbers, low, high);
            }
            if((high - low) == 1)
            {
                mid = high;
                // return numbers[high];
                break;
            }
            else if(numbers[mid] >= numbers[low])
            {
                low = mid;
            }
            else if(numbers[mid] <= numbers[high])
            {
                high = mid;
            }
        }
        return numbers[mid];
    }
};