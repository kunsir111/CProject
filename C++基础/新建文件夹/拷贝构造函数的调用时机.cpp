
//C++�п������캯������ʱ��ͨ�����������
//��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
//��ֵ���ݵķ�ʽ������������ֵ
//����ֵ��ʽ���ؾֲ�����I
#include<iostream>
using namespace std;
class Person{

public:
    Person(){
        cout<<"Person ��Ĭ�Ϲ��캯������"<<endl;
    }
    Person(int age){
        m_Age = age;
        cout<<"Person ���вι��캯������"<<endl;

    }
    Person(const Person &p){
        m_Age = p.m_Age;
        cout<<"Person �Ŀ������캯������"<<endl;
    }
    ~Person(){
        cout<<"Person ��������������"<<endl;
    }
    int m_Age;
};

//��ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01(){
    Person p1(20);
    Person p2(p1);
    cout<<"p2������Ϊ��"<<p2.m_Age<<endl;
}

//��ֵ���ݵķ�ʽ������������ֵ
void doWork(Person p){

}

void test02(){
    Person p;
    doWork(p);
}

//����ֵ��ʽ���ؾֲ�����
Person doWork2(){
    Person p1;
    return p1;
}

void test03(){
    Person p = doWork2();
}

int main(){
//    test01();
//    test02();
    test03();
    return 0;
}
