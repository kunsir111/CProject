
#include<iostream>
using namespace std;
//������
class Person{

public:
    //thisָ��ı�����ָ�볣����ָ��ָ���ǲ������޸ĵ�
    //const Person * const this;
    //�ڳ�Ա���������const�����ε���thisָ����ָ��ָ���ֵҲ�������޸�
    void showPerson() const
    {
//        this->m_A = 100;
        this->m_B = 100;
//        this = NULL; //thisָ�벻�����޸�ָ���ָ���
    }

    void func(){}

    int m_A;
    mutable int m_B; //�����������ʹ�ڳ������У�Ҳ�����޸����ֵ
};

void test01(){

    Person p;
    p.showPerson();
}
//������
void test02(){
     const Person p;
    p.m_B = 100;
    p.func();//�����󲻿��Ե�����ͨ��Ա��������Ϊ��ͨ��Ա���������޸�����|

}
int main(){
    test02();
    return 0;
}
