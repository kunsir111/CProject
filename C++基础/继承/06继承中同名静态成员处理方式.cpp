
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

//ͬ����̬��Ա����
void test01(){
    //1��ͨ���������
    Son s;
    cout<<"m_A = "<<s.m_A<<endl;
    cout<<"m_A = "<<s.Base::m_A<<endl;

    //2��ͨ����������
    cout<<"ͨ���������ʣ�"<<endl;
    cout<<"m_A = "<<Son::m_A<<endl;
    //��һ��::����ͨ��������ʽ����  �ڶ���::������ʸ�����������
    cout<<"m_A = "<<Son::Base::m_A<<endl;
}



//ͬ����̬����
void test02(){
    //ͨ���������
    Son s;
    s.func();
    s.Base::func();

    //ͨ����������
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
