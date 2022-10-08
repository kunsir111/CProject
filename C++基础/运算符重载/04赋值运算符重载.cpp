
#include<iostream>
using namespace std;

class Person{

public:
    Person(int age){
        m_Age = new int(age);
    }
    ~Person(){
        cout<<"Person���������ͷ�"<<*m_Age<<endl;
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }

    }

    //���ظ�ֵ�����
    Person& operator=(Person &p){
        //�������ṩǳ����
        //m_Age = p.m_Age;
        //Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
        if(m_Age != NULL){
            delete m_Age;
            m_Age = NULL;
        }
        //���
        m_Age = new int(*p.m_Age);
        return *this;
    }
    int *m_Age;
};

test01(){
    Person p1(18);
    Person p2(20);
    Person p3(30);


    p3 = p2 = p1;

    cout<<"p1�����䣺"<<*p1.m_Age<<endl;
    cout<<"p2�����䣺"<<*p2.m_Age<<endl;
    cout<<"p3�����䣺"<<*p3.m_Age<<endl;


}

int main(){
    test01();


    return 0;
}
