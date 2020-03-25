#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-47 题目：礼物的最大价值
    在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
    给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？


*/

/*
思路：

 */
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int hang = grid.size();
        int lie = grid[0].size();
        
        vector<vector<int>> maxVa(hang, vector<int>(lie, 0));
        for(int i = 0; i < hang; i++){
            for(int j = 0; j < lie; j++)
            {
                int left = 0, up = 0;
                if(i > 0)
                {
                    left = maxVa[i-1][j];
                }
                if(j > 0)
                {
                    up = maxVa[i][j - 1];
                }
                maxVa[i][j] = max(left, up) + grid[i][j];
            }
        }
        return maxVa[hang-1][lie - 1];
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}