
#include<iostream>
using namespace std;
//常函数
class Person{

public:
    //this指针的本质是指针常量，指针指向是不可以修改的
    //const Person * const this;
    //在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void showPerson() const
    {
//        this->m_A = 100;
        this->m_B = 100;
//        this = NULL; //this指针不可以修改指针的指向的
    }

    void func(){}

    int m_A;
    mutable int m_B; //特殊变量，即使在常函数中，也可以修改这个值
};

void test01(){

    Person p;
    p.showPerson();
}
//常对象
void test02(){
     const Person p;
    p.m_B = 100;
    p.func();//常对象不可以调用普通成员函数，因为普通成员函数可以修改属性|

}
int main(){
    test02();
    return 0;
}
