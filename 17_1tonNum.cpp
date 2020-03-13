#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-17 题目：打印从1到最大的n位数

*/

/*
思路：

 */

class Solution{
public:
    bool increase(char *num)
    {
        int nlen = strlen(num);
        int nTakeover = 0;
        bool isOver = false;
        for(int i = nlen - 1; i >= 0; --i){
            // 
            int numsum = num[i] - '0' + nTakeover;
            // ++
            if(i == nlen - 1){
                numsum++;
            }
            if(numsum > 9){
                // 结束
                if(i == 0)
                {   
                    isOver = true;
                    break;
                }
                else
                {
                    // 进位   
                    numsum -= 10;
                    num[i] = '0' + numsum;
                    nTakeover = 1;
                }

            }
            else
            {
                num[i] = '0' + numsum;
                break;
            }
            
        }
        return isOver;
    }   
    void printNum(char *num)
    {
        bool isbegin0 = true;
        int nlen = strlen(num);
        for(int n = 0; n < nlen; ++n)
        {
            if(isbegin0 && num[n] != '0'){
                isbegin0 = false;
            }
            if(!isbegin0){
                printf("%c", num[n]);
            }
        }
        cout<<endl;
    }
    void printMaxofNum(int n)
    {
        char *ptr = new char[n+1];
        memset(ptr, 0, sizeof(ptr));
        ptr[n] = '\0';
        while(!increase(ptr)){
            printNum(ptr);
        }

        delete ptr;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}