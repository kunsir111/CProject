
#include<iostream>
using namespace std;

class Base{
public:
    Base(){
        m_A = 100;
    }
    void func(){
        cout<<"Base 中成员函数调用"<<endl;
    }
    void func(int a){
        cout<<"Base func(int a)中成员函数调用"<<endl;
    }
    int m_A;
};

class Son : public Base{
public:
    Son(){
        m_A = 200;
    }
    void func(){
        cout<<"Son 中成员函数调用"<<endl;
    }
    void func(int a){
        cout<<"Son func(int a)中成员函数调用"<<endl;
    }
    int m_A;
};


//同名的成员属性处理
void test01(){
    Son s;
    cout<<"Son 下 m_A = "<<s.m_A<<endl;
    //如果通过子类对象访问到父类中同名成员，需要加作用域
    cout<<"Base 下 m_A = "<<s.Base::m_A<<endl;
}
//同名的成员函数处理
void test02(){
    Son s;
    s.func();
    s.Base::func();
    s.func(2);
    s.Base::func(2);
}

int main(){
//    test01();
    test02();
    return 0;
}
