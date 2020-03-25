#include "bits/stdc++.h"
// #include <strin
using namespace std;
/* 
剑指offer-45 题目：把数排成最小的数

*/

/*
思路：

 */
bool compart(int a, int b){
    string sa, sb;
    sa += to_string(a);
    sa += to_string(b);
    sb += to_string(b);
    sb += to_string(a);
    return sa < sb;
}
class Solution {
public:
  
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), compart);
        string s;
        for(auto i : numbers)
        {
            s += to_string(i);
        }
        return s;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}