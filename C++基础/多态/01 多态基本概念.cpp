#include<iostream>

using namespace std;

class Animal{
public:
    //虚函数
    virtual void speak(){
        cout<<"动物在说话"<<endl;
    }
};

//猫类
class Cat: public Animal{
public:
    void speak(){
        cout<<"小猫在说话"<<endl;
    }
};

//狗类
class Dog: public Animal{
public:
    void speak(){
        cout<<"小狗在说话"<<endl;
    }
};

//地址早绑定，在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数就不能早绑定,需要在

//动态多态满足条件
//1、有继承关系
//2、子类重写父类的虚函数

//动态多态的使用
//父类的指针或引用 执行子类对象

void doSpeak(Animal &animal){
    animal.speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02(){
    cout<<"sizeof animal = "<<sizeof(Animal)<<endl;
}

int main(){
//    test01();
    test02();
    return 0;
}
