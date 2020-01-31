#include<vector>
#include<iostream>
using namespace std;
/* 
剑指offer-4 题目：不修改数组找出重复的数字
    在一个长度为n+1的数组里的所有数字都在1-n的范围内。 
    所以数组中至少有一个数字是重复的，请找出数组中任意一个重复的数字，
    但不能修改输入的数组。
    例如，如果输入长度为8的数组{2,3,5,4,3,2,6,7}，那么对应的输出的重复数字是2或者3。
*/

/*
思路：*/ 
class Solution1{
    // Parameters:
    //        numbers:     an array of integers 整型数组
    //        length:      the length of array numbers 数组长度
    int getDuplication(const int *numbers, int length) {
        vector<int> vec(length+1, 0);
        for(int i = 0; i < length; i++){
            if(vec[numbers[i]] == 0){
                vec[numbers[i]] == numbers[i];
            }
            else
            {
                return numbers[i];  
            }
        }
        return -1;
    }
};

class Solution2{
    // Parameters:
    //        numbers:     an array of integers 整型数组
    //        length:      the length of array numbers 数组长度
    //二分的思想
    int getDuplication(const int *numbers, int length) {
        if(numbers == nullptr || length <= 0){
            return -1;
        }
        int start = 1;
        int end = length - 1;
        while(start <= end){
            int middle = start + ((end - start)>>1);
            int count = countRange(numbers, length,start, middle);
            if(end == start){
                if(count > 1){
                    return start;
                }
                else
                {
                    break;
                }
            }
            if(count > (middle - start +1)){
                end = middle
                
                ;
            }
            else
            {
                start = middle + 1;
            }
            
        }
        return -1;
    }
    int countRange(const int *numbers, int length, int start, int end){
        if(numbers == nullptr || length <= 0){
            return 0;
        }
        int count = 0;
        for(int i = 0; i < length; i++){
            if(numbers[i] >= start && numbers[i] <= end){
                count++;
            }
        }
        return count;
    }
};
int main(){

    system("pause");
    return 0;
}