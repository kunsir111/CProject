//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
#include<iostream>
using namespace std;
class Person{
public:
    //静态成员函数
    static void func(){
        m_A = 100; //
        m_B = 200;
        cout<<"static void func调用"<<endl;
    }
    static int m_A; //静态成员变量
    int m_B; //非静态成员变量
private:
    static void func2(){
    }
};
void test01(){
    //1、通过对象访问
    Person p;
    p.func();
    //2、通过类名访问
    Person::func();

//    Person::func2(); //静态成员函数也有访问权限
}
int Person::m_A = 0;
int main(){
    test01();
    return 0;
}
