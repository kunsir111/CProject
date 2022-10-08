#include<iostream>
using namespace std;
class Person{

public:
    Person(int age){
         this->age = age;
    }
    Person& PersonAddAge(const Person &p){
        this->age += p.age;
        //返回对象本身
        return *this;
    }
    int age;
};
//1解决名称冲突
//2返回对象本身用*this

void test01(){
    Person p(10);
    cout<<p.age<<endl;
}

void test02(){
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
    cout<<"p2的年龄为："<<p2.age<<endl;
}

int main(){
//    test01();
    test02();
    return 0;
}
