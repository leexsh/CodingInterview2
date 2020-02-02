#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer-5 题目：替换空格
    请实现一个函数，将一个字符串中的每个空格替换成“%20”。
    例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

/*
思路：
    优化思路  
    双指针 从前往后
 */
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length <= 0){
            return;
        }
        int lenofOri = 0;//str的原始长度
        int numofBlank = 0;//空格个数
        int i = 0;
        // 计算str长度和空格的个数
        while(str[i] != '\0'){
            ++lenofOri;
            if(str[i] == ' '){
                ++numofBlank;
            }
            ++i;
        }
        // 重新设定 改变后的长度
        int lenofNew = lenofOri + numofBlank * 2;
        if(lenofNew > length){
            return;
        }
        int indexofOri = lenofOri;
        int indexofNew = lenofNew;
        // 拷贝过程
        while(indexofOri >= 0 && indexofNew > indexofOri){
            if(str[indexofOri] == ' '){
                str[indexofNew--] = '0';
                str[indexofNew--] = '2';
                str[indexofNew--] = '%';
            }else
            {
                str[indexofNew--] = str[indexofOri];
            }
            indexofOri--;
        }

    }
};

/*
    进阶：有两个排序的数组a b 全部归并到a中 仍然是按照从小到大的顺序
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if(m <= 0 || n <= 0){
        return;
    }        
    int len = m + n;
    while(m >= 0 && n >= 0){}
}
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}