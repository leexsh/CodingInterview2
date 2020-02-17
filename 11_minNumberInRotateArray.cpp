#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-11 题目：旋转数组中的最小数值
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。  输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

/*
思路：
    1.二分
 */

// 两个指针 一个数组头 一个数组尾
// 每次mid 如果mid大于头 头到mid 如果mid小于尾 尾到mid
// 剑指offer
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()){
            return 0;
        }
        // 左右
        int left = 0;
        int right = rotateArray.size() - 1;
        // mid
        int mid = 0;
        while(rotateArray[left] >= rotateArray[right]){
            // 左右挨着 最小是右
            if(right - left == 1){
                mid = right;
                break;
            }
            // 改变左右值
            mid = left + (right - left)/2;
            if(rotateArray[left] <= rotateArray[mid]){
                left = mid;
            }
            else if(rotateArray[mid] <= rotateArray[right]){
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};
// 改进
// 为了应对 比如 {0,1,1,1,1}旋转后为{1，1,0,1,1}的情况 加了个线性查找
class Solution1 {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()){
            return 0;
        }
        // 左右
        int left = 0;
        int right = rotateArray.size() - 1;
        // mid
        int mid = 0;
        
        while(rotateArray[left] >= rotateArray[right]){
            // 左右挨着 最小是右
            if(right - left == 1){
                mid = right;
                break;
            }
            // 改变左右值
            mid = left + ((right - left)>>1);
            if(rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]){
                return findMin(rotateArray, left, right);
            }
            if(rotateArray[left] <= rotateArray[mid]){
                left = mid;
            }
            else if(rotateArray[mid] <= rotateArray[right]){
                right = mid;
            }
        }
        return rotateArray[mid];
    }
    int findMin(vector<int> & nums, int left, int right){
        int res = nums[left];
        for(auto i = left; i <= right; i++ ){
            if(nums[i] < res){
                res = nums[i];
            }
        }
        return res;
    }
};

// 右边不动 左边逐渐靠近最小值
class Solution2 {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
       if(rotateArray.empty()){
           return 0;
       }
       int left = 0;
       int right = rotateArray.size() - 1;
       while(rotateArray[left] > rotateArray[right]){
           int mid = left + (right - left) / 2;
           if(rotateArray[mid] >= rotateArray[left]){
               left = mid + 1;
           }
           else if(rotateArray[mid] < rotateArray[right]){
               right = mid;
           }
       }
       return rotateArray[left];
    }
    int findMin(vector<int> & nums, int left, int right){
        int res = nums[left];
        for(auto i : nums){
            if(i < res){
                res = i;
            }
        }
        return res;
    }
};

int main(){
    // vector<int> vec{3,4,5,1,2};
    // int x = findMin(vec);
    // cout<<x<<endl;
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}