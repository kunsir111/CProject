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
        m_A = 10; //�����еĹ���Ȩ�޳�Ա����������Ȼ�ǹ���Ȩ��

        m_B = 20; //�����еı���Ȩ�޳�Ա����������Ȼ�Ǳ���Ȩ��
//        m_C = 30; //�����е�˽��Ȩ�޳�Ա������ʲ���
    }
};

class Son2: protected Base1{
public:
    void func(){
        m_A = 100;//�����й���Ȩ�޵������б�Ϊ����Ȩ��
        m_B = 100; //�����б���Ȩ�޵���������Ȼ�Ǳ���Ȩ��
//        m_C = 100; //������˽�г�Ա������ʲ���
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
//    s2.m_A = 100; //����Ȩ��������ʲ���
//    s.m_B; //��Son1��m_B�Ǳ���Ȩ�ޣ�������ʲ���
    Son3 s3;
    s3.func();
}


using namespace std;
int main(){
    test01();
    return 0;
}

