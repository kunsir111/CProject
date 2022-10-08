#include<iostream>
using namespace std;

class Student{

public: //公共权限

    //类中的属性和行为统一称为成员
    //属性 成员属性 成员变量
    //行为 成员函数 成员方法

    //属性
    string m_Name;
    int m_id;


    //行为
    void showStudent(){
        cout<<"姓名: "<<m_Name<<"\t学号："<<m_id<<endl;
    }
    void setName(string name){
        m_Name = name;
    }
    void setId(int id){
        m_id = id;
    }
};

int main(){
    Student stu1, stu2;
    stu1.m_Name = "张三";
    stu1.m_id = 1343;
    stu1.showStudent();
    stu2.setName("李安坤");
    stu2.setId(123);
    stu2.showStudent();
    return 0;
}
