#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-9 题目：两个栈实现队列
    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

/*
思路：
    来元素就放进stack1中
    stack2中有元素 不能放  而且 如果向stack2中放元素 就要全部放完
 */
// 两个栈实现队列
class MyQueue
{
public:
    // 入队
    void push(int node) {
        stack1.push(node);
    }

    // 出队
    int pop() {
        if(stack2.size() <= 0){
            while(!stack1.empty()){
                int node = stack1.top();
                stack1.pop();
                stack2.push(node);
            }
        }
        int node = stack2.top();
        stack2.pop();
        return node;
    }
    // 判空
    bool empty(){
        if(!stack1.empty() && !stack2.empty()){
            return true;
        }else
        {
            return false;
        }
    }
    // 求队头
    int peek(){
        if(stack1.empty() && stack2.empty()){
            return -1;
        }
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
// 两个队列实现栈
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    // 入栈
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    // 出栈
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    /** Get the top element. */
    // 栈顶元素
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q2.push(val);
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return val;
    }
    
    /** Returns whether the stack is empty. */
    // 判空
    bool empty() {
        if(q1.empty() && q2.empty()){
            return true;
        }
        else
        {
            return false;
        }
    }
private:
    queue<int> q1;
    queue<int> q2;
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}