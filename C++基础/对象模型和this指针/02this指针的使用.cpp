#include<iostream>
using namespace std;
class Person{

public:
    Person(int age){
         this->age = age;
    }
    Person& PersonAddAge(const Person &p){
        this->age += p.age;
        //���ض�����
        return *this;
    }
    int age;
};
//1������Ƴ�ͻ
//2���ض�������*this

void test01(){
    Person p(10);
    cout<<p.age<<endl;
}

void test02(){
    Person p1(10);
    Person p2(10);
    //��ʽ���˼��
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout<<"p2������Ϊ��"<<p2.age<<endl;
}

int main(){
//    test01();
    test02();
    return 0;
}
