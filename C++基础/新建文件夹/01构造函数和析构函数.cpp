
#include<iostream>
using namespace std;
//对象的初始化和清理
//1、构造函数进行初始化
class Person{
public:
    //1、构造函数
    //没有返回值 不用写函数类型
    //构造函数可以重载
    //
    //
    Person(){
        cout<<"Person 的构造函数调用"<<endl;
    }
    //2、析构函数
    ~Person(){
        cout<<"Person 的析构函数"<<endl;
    }
};

void test01(){
    Person p;
}

int main(){
//    test01();
    Person p;
    return 0;
}
