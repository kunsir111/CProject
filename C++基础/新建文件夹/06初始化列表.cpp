
#include<iostream>
using namespace std;
class Person{

public:
//    //��ʼ���б����
//    Person(int a, int b, int c){
//        m_A = a;
//        m_B = b;
//        m_C = c;
//    }
    //��ʼ���б��ʼ������
    Person(int a, int b, int c): m_A(a), m_B(b), m_C(c){
    }
    int m_A;
    int m_B;
    int m_C;
};

void test01(){
//    Person p(1, 2, 3);
    Person p(3, 2, 1);
    cout<<"m_A = "<<p.m_A<<endl;
    cout<<"m_B = "<<p.m_B<<endl;
    cout<<"m_C = "<<p.m_C<<endl;
}

int main(){
    test01();
    return 0;
}
