
#include<iostream>
using namespace std;

class Base{
public:
    static int m_A;
    static void func(){
        cout<<"Base - static void func()"<<endl;
    }
    static void func(int a){
        cout<<"Base - static void func(int a)"<<endl;
    }
};

int Base::m_A = 100;

class Son :public Base{
public:
    static int m_A;
    static void func(){
        cout<<"Son - static void func()"<<endl;
    }
    static void func(int a){
        cout<<"Son - static void func(int a)"<<endl;
    }
};

int Son::m_A = 200;

//同名静态成员属性
void test01(){
    //1、通过对象访问
    Son s;
    cout<<"m_A = "<<s.m_A<<endl;
    cout<<"m_A = "<<s.Base::m_A<<endl;

    //2、通过类名访问
    cout<<"通过类名访问："<<endl;
    cout<<"m_A = "<<Son::m_A<<endl;
    //第一个::代表通过类名方式访问  第二个::代表访问父类作用域下
    cout<<"m_A = "<<Son::Base::m_A<<endl;
}



//同名静态函数
void test02(){
    //通过对象访问
    Son s;
    s.func();
    s.Base::func();

    //通过类名访问
    Son::func();
    Son::Base::func();
    Son::func(10);
    Son::Base::func(10);
}

int main(){
//    test01();
    test02();
    return 0;
}
