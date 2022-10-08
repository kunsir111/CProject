#include<iostream>

class Base1{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1: public Base1{

public:
    void func(){
        m_A = 10; //父类中的公共权限成员到子类中依然是公共权限

        m_B = 20; //父类中的保护权限成员到子类中依然是保护权限
//        m_C = 30; //父类中的私有权限成员子类访问不到
    }
};

class Son2: protected Base1{
public:
    void func(){
        m_A = 100;//父类中公共权限到子类中变为保护权限
        m_B = 100; //父类中保护权限到子类中依然是保护权限
//        m_C = 100; //父类中私有成员子类访问不到
    }
};

class Son3: private Base1{
public:
    void func(){
        m_A = 100;
        m_B = 1000;
    }
};


void test01(){
    Son1 s;
    s.func();
    s.m_A;
    Son2 s2;
    s2.func();
//    s2.m_A = 100; //保护权限类外访问不到
//    s.m_B; //到Son1中m_B是保护权限，类外访问不到
    Son3 s3;
    s3.func();
}


using namespace std;
int main(){
    test01();
    return 0;
}

