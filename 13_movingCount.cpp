#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-13 题目：机器人运动范围
    地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
    每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
    例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
    但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

/*
思路：
    回溯
 */
class Solution {
public:

    int movingCount(int threshold, int rows, int cols)
    {
        // 边界条件
        if(threshold < 0 || rows <= 0 || cols <= 0){
            return 0;
        }
        // 访问标志
        vector<vector<bool>> visited(rows,vector<bool>(cols, false));
        
        int res = getCount(threshold,rows,cols,0,0,visited);
        return res;
    }
    // 回溯算法
    int getCount(int threshold, int rows, int cols, int row, int col,vector<vector<bool>> &visited){
        int count = 0;
        if(row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold
            && visited[row][col] == false){
            visited[row][col] = true;
            count = 1 + getCount(threshold, rows, cols, row + 1, col, visited) 
                    + getCount(threshold, rows, cols, row - 1, col, visited) 
                    + getCount(threshold, rows, cols, row, col + 1, visited)
                    + getCount(threshold, rows, cols, row, col - 1, visited);
        }
        return count;
    }
    // 获取个位数之和
    int getDigitSum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }


};
int main(){
    Solution s;
    cout<<s.getDigitSum(134);
    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}