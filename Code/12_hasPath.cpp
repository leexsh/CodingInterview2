#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-12 题目：矩阵中的路径
    题目描述
    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
    路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
    如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 例如 
        a   b   c   e
        s   f   c   s
        a   d   e   e
​    矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
    因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

/*
思路：
    回溯
 */


class Solution1 {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        // 预判断
        if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr){
            return false;
        }
        // 标志位 判断是否遍历过
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);

        // 字符串的遍历
        int pathLength = 0;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(coreDeal(matrix, rows, cols, row, col, str,pathLength, visited)){
                    return true;
                }
            }
        }
        // 释放空间
        delete[] visited;
        return false;
    }
    bool coreDeal(char *matrix, int rows, int cols, int row, int col, const char *str,
        int &pathLength, bool *visited){
            // 终止条件
            if(str[pathLength] == '\0'){
                return true;
            }
            bool hasPath = false;
            if(row >= 0 && row < rows && col >= 0 && col < cols && str[pathLength] == matrix[row * cols + col]
                && visited[row * cols + col] == false){
                    ++pathLength;
                    visited[row * cols + col] = true;
                    hasPath = coreDeal(matrix, rows, cols, row, col - 1,str, pathLength, visited)
                        || coreDeal(matrix, rows, cols, row - 1, col, str,pathLength, visited)
                        || coreDeal(matrix, rows, cols, row, col + 1, str,pathLength,visited)
                        || coreDeal(matrix, rows, cols, row + 1, col, str, pathLength,visited)
                    ;
                    if(!hasPath){
                        --pathLength;
                        visited[row * cols + col] = false;
                    }
                }
            return hasPath;
        }



};

int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}