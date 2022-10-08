
//深浅拷贝是面试经典问题，也是常见的一个坑
//浅拷贝:简单的赋值拷贝操作
//深拷贝:在堆区重新电请空间，进行拷贝操作
//总结:如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

#include<iostream>
using namespace std;

//深拷贝与浅拷贝
class Person{

public:

    Person(){
        cout<<"Person 的无参构造函数调用"<<endl;
    }
    Person(int age, int height){
        m_Age = age;
        m_Height = new int(height);
        cout<<"Person 的无参构造函数调用"<<endl;
    }
    Person(const Person &p){
        m_Age = p.m_Age;
        m_Height = new int(*p.m_Height);
        cout<<"Person 的拷贝构造函数调用"<<endl;
    }
    ~Person(){
        //析构代码，将堆区开辟数据释放
        if(m_Height != NULL){

            delete m_Height;
            m_Height = NULL; //防止出现野指针
        }
        cout<<"Person 的析构函数调用"<<endl;
    }
    int m_Age;
    int *m_Height;
};

void test01(){
    Person p1(18, 170);
    cout<<"p1的年龄为"<<p1.m_Age<<"身高为："<<*p1.m_Height<<endl;
    Person p2(p1);
    cout<<"p2的年龄为"<<p2.m_Age<<"身高为："<<*p2.m_Height<<endl;
}

int main(){
    test01();
    return 0;
}
