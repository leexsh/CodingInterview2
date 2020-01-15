#include <iostream>
using namespace std;
/* 
剑指offer-2 题目：单例模式

*/

/*
思路：

 */

// 简单的 不完善的模式 初始版本 饿汉模式
// 只创建了对象 没有释放 存在内存泄漏
class Signleton1{
public:
    static Signleton1* getInstance(){
        if(instance1 == nullptr){
            instance1 = new Signleton1();
        }
        return instance1;
    }
private:
    static Signleton1 *instance1;// 静态指针
    
    // 构造函数
    Signleton1(){}
    // 析构函数
    ~Signleton1(){}
    // 拷贝构造
    Signleton1(const Signleton1 &){}
    // 赋值运算符
    Signleton1 &operator=(const Signleton1 &){}
};
// 静态指针 类外初始化
Signleton1 *Signleton1::instance1 = nullptr;


// 单线程 安全版本
//程序结束的时候 自动调用Deletor的析构函数
class Signleton2{
public:
    Signleton2 *getInstance()
    {
        if(instance2 != nullptr){
            instance2 =new Signleton2();
        }
        return instance2;
    }
private:
    class Deletor{
    public: 
        ~Deletor(){
            if(Signleton2::instance2 != nullptr){
                delete Signleton2::instance2;
            }
        }
    };
    static Deletor deletor;
private:
    static Signleton2 *instance2;

    Signleton2(){}
    ~Signleton2(){}
    Signleton2(const Signleton2 &){}
    Signleton2 & operator=(const Signleton2 &){}

};
Signleton2 *Signleton2::instance2 = nullptr;


// 懒汉模式和饿汉模式
// 饿汉式单例模式：在类加载时就完成了初始化，所以类加载比较慢、获取对象的速度快、以空间换取时间模式、线程安全、
// 懒汉式单例模式：在类加载时不初始化、按照需求创建实例、以时间换取空间模式

// 饿汉模式
// 饿汉单例：在类装载时完成了初始化，静态成员对象初始化成功
// 类加载速度相比懒汉慢，但获取对象的速度快，是一种典型的以时间换取空间的做法
// 优点：线程安全
// 缺点：不管你用不用这个对象，他都会先创建出来，会造成浪费内存空间
class Signleton3{
public:
    void Destory(){
        delete instance3;
        instance3 = nullptr;
    }
    Signleton3* getInstance(){
        return instance3;
    }
private:
    static Signleton3 *instance3;
    Signleton3(){
    }

    Signleton3(const Signleton3 & ){}
    Signleton3 & operator=(const Signleton3&){}
};
Signleton3 * Signleton3::instance3 = new Signleton3();


class Signleton4{

};
int main(){

    system("pause");
    return 0;
}