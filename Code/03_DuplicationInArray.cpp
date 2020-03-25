#include<set>
#include<iostream>
using namespace std;
/* 
剑指offer-3 题目：数组中的重复的数字
    在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
    数组中某些数字是重复的，但不知道有几个数字是重复的。
    也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
    例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/

/*
思路：
    1.set去重复
    2.将每个元素放在对应的位置 如果某个元素和对应的下标位置不一致 则是存在重复的元素
 */
// 方法1 set
class Solution1{
    // Parameters:
    //        numbers:     an array of integers 整型数组
    //        length:      the length of array numbers 数组长度
    //        duplication: (Output) the duplicated number in the array number 重复的元素
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false 返回值 true或false
    bool duplicate(int numbers[], int length, int* duplication) {
        // 判空
        if(numbers == nullptr || length <= 0){
            return false;
        }
        int i;
        // 判断元素的合法性
        for(i = 0; i < length; i++){
            if(numbers[i] < 0 || numbers[i] > length - 1){
                return false;
            }
        }
        set<int> s;//集合
        // O(n) 遍历数组 查找重复的元素
        for(i = 0; i < length; i++){
            if(s.count(numbers[i])){
                *duplication = numbers[i];
                return false;
            }
            else
            {
                /* code */
                s.insert(numbers[i]);
            }
        }
        // 找不到 返回false
        return false;
    }
};
class Solution2{
public:
   // Parameters:
    //        numbers:     an array of integers 整型数组
    //        length:      the length of array numbers 数组长度
    //        duplication: (Output) the duplicated number in the array number 重复的元素
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false 返回值 true或false
    bool duplicate(int numbers[], int length, int* duplication) {
        // 非空判断
        if(numbers == nullptr | length <= 0){
            return false;
        }
        // 数值合法性判断
        int i;
        for(i = 0; i < length; i++){
            if(numbers[i] < 0 || numbers[i] > length - 1){
                return false;
            }
        }
    for(i = 0; i < length; i++){
        // 某个位置和前面的相同  重复
        while(numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            // 交换numbers[i]和number[number[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
        return false;
    }
};
int main(){

    system("system");
    return 0;
}