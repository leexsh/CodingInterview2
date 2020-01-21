#include<vector>
#include<iostream>
using namespace std;

/* 
剑指offer-4 题目：二维数组中查找
    类似二分
*/

/*
思路：

 */
class Solution1 {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool flag = false;
        if(array.empty()){
            return flag;
        }
        //从左下角开始 
        int hang = array.size() - 1;
        int lie = 0;
        while(hang >= 0 && lie < array[0].size()){
            if(array[hang][lie] == target){
                flag = true;
                break;
            }
            else if(array[hang][lie] > target){
                hang--;
            }
            else
            {
                /* code */
                lie++;
            }
        }
        
        return flag;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}