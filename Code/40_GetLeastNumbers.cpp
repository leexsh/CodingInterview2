#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-40 题目：数组中最小的k个数

*/

/*
思路：

 */
// 法1 排序
class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> vec(arr.begin(), arr.begin() + k);
        return vec;
    }
};

// 法2 利用stl的优先队列
class Solution2 {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> arr, int k) {
        vector<int> vec;
        if(k <= 0 || arr.size() < k){
            return vector<int>();
        }
        priority_queue<int> que(arr.begin(), arr.begin() + k);
        for(int i = k; i < arr.size(); ++i){
           
           
            if(arr[i] < que.top()){
                que.pop();
                que.push(arr[i]);
            } 
        }
        while(!que.empty()){
            vec.push_back(que.top());
            que.pop();
        }
        return vec;
    }

};
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
    if(input.empty() || k <= 0 || k > input.size()){
            return vector<int>();
        }
        vector<int> heapVec(input.begin(), input.begin() + k);
        for(int i = 0; i < k; i++){
            heapInsert(heapVec, i);
        }
        for(int i = k ; i < input.size(); ++i)
        {
            if(input[i] < heapVec[0]){
                heapVec[0] = input[i];
                heapify(heapVec, 0);
            }
        }
        return heapVec;
    }
private:

    // 交换
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    // 建堆
    void heapInsert(vector<int> &nums, int index)
    {
        while(nums[index] > nums[(index - 1) / 2])
        {
            swap(nums, index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }
    // 调整
    void heapify(vector<int> &nums, int index)
    {
        int left = index * 2 + 1;
        while(left < nums.size())
        {
            int biggest = nums[left] < nums[left + 1] && (left + 1) < nums.size() ? left + 1 : left;
            biggest = nums[index] > nums[biggest] ? index : biggest;
            if(biggest == index){
                break;
            }
            swap(nums, index, biggest);
            index = biggest;
            left = index * 2 + 1;
        }
    }
};




class Solution3 {
public:
    vector<int> getLeastNumbers(vector<int> arr, int k) {
        
    if(arr.empty() || k <= 0 || k > arr.size()){
            return vector<int>();
        }
        vector<int> heapVec(arr.begin(), arr.begin() + k);
        for(int i = 0; i < k; i++){
            heapInsert(heapVec, i);
        }
        for(int i = k ; i < arr.size(); ++i)
        {
            if(arr[i] < heapVec[0]){
                heapVec[0] = arr[i];
                heapify(heapVec, 0);
            }
        }
        return heapVec;
    }
private:

    // 交换
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    // 建堆
    void heapInsert(vector<int> &nums, int index)
    {
        while(nums[index] > nums[(index - 1) / 2])
        {
            swap(nums, index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }
    // 调整
    void heapify(vector<int> &nums, int index)
    {
        int left = index * 2 + 1;
        while(left < nums.size())
        {
            int biggest = nums[left] < nums[left + 1] && (left + 1) < nums.size() ? left + 1 : left;
            biggest = nums[index] > nums[biggest] ? index : biggest;
            if(biggest == index){
                break;
            }
            swap(nums, index, biggest);
            index = biggest;
            left = index * 2 + 1;
        }
    }
};


int main(){
    Solution3 s;
    vector<int> vec{3,2,1};
    vector<int> v = s.getLeastNumbers(vec,2);
    for(auto i : v)
    {   
        cout<<i<<endl;
    }
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}