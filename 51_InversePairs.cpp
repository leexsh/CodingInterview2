#include "bits/stdc++.h"
using namespace std;
/* 
剑指offer- 题目：

*/

/*
思路：

 */

class Solution {
public:
    int merge(vector<int> &data, int low, int mid, int high)
    {
        vector<int> help(high - low + 1, 0);
        int p1 = low, p2 = mid + 1;
        int i = 0;
        int counts = 0;
        while(p1 <= mid && p2 <= high)
        {
            counts += data[p1] < data[p2] ? high - p2 + 1 : 0;
            if(counts > 1000000007){
                counts %= 1000000007;
            }
            help[i++] = data[p2] > data[p1] ? data[p1++] : data[p2++];
        }
        while(p1 <= mid)
        {
            help[i++] = data[p1++];
        }
        while(p2 <= high)
        {
            help[i++] = data[p2++];
        }
        for(i = 0; i < help.size(); i++)
        {
            data[low + i] = help[i];
        }
        return counts;
    }
    int sort(vector<int> &data, int low, int high)
    {
        if(low == high){
            return 0;
        }
        int mid = (low + high) >> 1;
        return (sort(data,low, mid) + sort(data, mid + 1, high) + merge(data,low, mid, high)) % 1000000007;
    }
    int InversePairs(vector<int> data) {
        if(data.size() < 2){
            return 0;
        }
        int anse = sort(data, 0,data.size()-1);
        return anse ;
    }
};
int main(){

    // cout<<"iiiii"<<endl; 
    system("pause");
    return 0;
}
