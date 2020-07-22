#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

// 恶汉模式 绝对安全 在创建对象的时候就进行初始化
class Singleton1{
public:
    static Singleton1* getInstance()
    {
        return Singleton1;
    }
private:
    Singleton1(){}
    Singleton1(const Singleton1&);
    Singleton1& operator=(const Singleton1&);
    static Singleton1 *instance;
};
Singleton1 Singleton1::instance = new Singleton1;




// 懒汉模式 多线程下 非线程安全的
class Singleton
{
public:
    static Singleton* getInstance(){
        if (instance == nullptr) {
            instance = new *Singleton;
            return instance;
        }
    }
private:
    static Singleton *instance;
    Singleton(){}
    Singleton(const Singleton &);
    Singleton& operator=(cosnt Singleton&);

};
Singleton* Singleton::instance = nullptr;


mutex mt;
// 利用双检锁实现的线程安全的懒汉模式
class Singleton2
{
public:
    static Singleton2* getInstance()
    {
        if (instance == nullptr) {
            lock_guard<mutex> lg(mt);
            if (instance == nullptr) {
                instance = new Singleton2;
                return instance;
            }
        }
    }
private:
    Singleton2(){}
    Singleton2(const Singleton2&);
    Singleton2& operator=(const Singleton2&);
    static Singleton2 *instance;
};
Singleton2* Singleton2::instance = nullptr;

// 懒汉模式  双检锁 + 自动回收
class Singleton3()
{
public:
    static Singleton3* getInstance()
    {
        if (instance == nullptr) {
            lock_guard<mutex> lg(mt);
            if (instance == nullptr) {
                instance = new instance;
                return instance;
            }
        }
    }
    class GC{
        public:
        ~GC(){
            if (Singleton3::instance) {
                delete Singleton3::instance;
            }
        }
    };
private:
    Singleton3(){}
    Singleton3(const Singleton3&);
    Singleton3& operator(const Singleton3&);
    static Singleton3 *instance;
    static GC gc;
}
Singleton3* Singleton3::instance = nullptr;

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