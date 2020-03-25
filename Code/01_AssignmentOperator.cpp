#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
/* 
剑指offer-1 题目：赋值运算符函数
    如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
*/

/*
 思路：

 */
class CString{
public:
    CString(char *pData = nullptr);
    CString(const CString &str);
    ~CString(void);
    CString &operator=(const CString &str);
    void Print();
private:
    char *m_pData;
};

// 构造函数
CString::CString(char *pData){
    // pData为空
    if(pData == nullptr){
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int len = strlen(pData);
        m_pData = new char[len + 1];
        strncpy(m_pData, pData, len + 1);
    }
    
}


// 拷贝构造函数
CString::CString(const CString &str){
    int len = strlen(str.m_pData);
    m_pData = new char[len];
    strncpy(m_pData, str.m_pData, len + 1);
}


// 析构函数
CString::~CString(void){
    delete[] m_pData;
}


// 拷贝赋值运算符
CString & CString::operator=(const CString &str){
    if(&str != this){
        CString strTemp(str);
        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = this->m_pData;
        this->m_pData = pTemp;
    }
    return *this;


}


int main(){
    cout<<"xxx"<<endl;
    
    system("pause");
    return 0;
}