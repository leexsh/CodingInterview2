#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-30 题目：包含min函数的栈

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。 
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
*/

/*
思路：

 */
// 向栈中push两个 当前值和最小值
class Solution {
public:
  
    void push(int value) {
        // 入栈
        st.push(value);
        if(value < minN){
            minN = value;   
        }
        // 最小值入栈
        st.push(minN);
    }
    // 出栈
    void pop() {
        st.pop();
        st.pop();
    }
    int top() {
        // 最小值出栈
        minN = st.top();
        st.pop();
        // 获取top()
        int num = st.top();
        // 最小值入栈
        st.push(minN);
        return num;
    }
    int min() {
        // top就是最小值
        return st.top();
    }
private:
    stack<int> st;
    int minN = INT_MAX;
};

// 两个栈实现
class Solution1 {
public:
    stack<int> s1,s2;
    void push(int value) {
        s1.push(value);
        if(s2.empty()){
            s2.push(value);
        }else{
            // int num = s2.top() > value ? value:s2.top();
            // s2.push(num);
              int min = s2.top();
            value<=min?s2.push(value):s2.push(min);
        }
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};
int main(){
    Solution1 s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<"s.min"<<s.min()<<" s.top()"<<s.top()<<endl;
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}