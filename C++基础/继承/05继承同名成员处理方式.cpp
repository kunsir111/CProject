
#include<iostream>
using namespace std;

class Base{
public:
    Base(){
        m_A = 100;
    }
    void func(){
        cout<<"Base �г�Ա��������"<<endl;
    }
    void func(int a){
        cout<<"Base func(int a)�г�Ա��������"<<endl;
    }
    int m_A;
};

class Son : public Base{
public:
    Son(){
        m_A = 200;
    }
    void func(){
        cout<<"Son �г�Ա��������"<<endl;
    }
    void func(int a){
        cout<<"Son func(int a)�г�Ա��������"<<endl;
    }
    int m_A;
};


//ͬ���ĳ�Ա���Դ���
void test01(){
    Son s;
    cout<<"Son �� m_A = "<<s.m_A<<endl;
    //���ͨ�����������ʵ�������ͬ����Ա����Ҫ��������
    cout<<"Base �� m_A = "<<s.Base::m_A<<endl;
}
//ͬ���ĳ�Ա��������
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
