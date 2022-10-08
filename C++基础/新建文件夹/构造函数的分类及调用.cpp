#include<iostream>
using namespace std;

//1、构造函数的分类及调用
//分类
//  按照参数进行分类   无参构造 （默认构造）和有参构造
//  按照类型分类       普通构造  拷贝构造
class Person{
public:
    Person(){
        cout<<"Person 的无参构造函数"<<endl;
    }
    Person(int a){
        age = a;
        cout<<"Person 的有参构造函数"<<endl;
    }
    ~Person(){
        cout<<"Person 的析构函数"<<endl;
    }
    //拷贝构造函数
    Person(const Person &p){
        //将传入的人身上得所有属性拷贝到我身上
        age = p.age;
        cout<<"Person 的拷贝函数"<<endl;
    }
    int age;
};

void test01(){
    //1、括号法
//    Person p1;
//    Person p2(2);
//    Person p3(p2);
    //注意事项1
    //调用默认构造函数时，不要加（）
    //因为 Person p1() 是一个函数声明;
//    cout<<p2.age<<endl;
//    cout<<p3.age<<endl;
    //2、显示法
    Person p1;
    Person p2 = Person(10);
    Person p3 = Person(p2);
//    Person(10); //匿名函数 特点：当前行执行结束后，系统会立即回收掉对象
    //3、=隐式转换法
    Person p4 = 10;
    Person p5 = p4;
}

int main(){
    test01();
    return 0;
}
