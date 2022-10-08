
#include<iostream>
using namespace std;

//成员属性设置为私有
//1、可以自己控制读写权限
//2、对于写权限，可以检测数据的有效性


//设计人类
class Person{
private:
    //姓名
    string m_Name;
    //年龄
    int m_Age;
    //情人
    string m_Lover;

public:
    void setName(string name){
        m_Name = name;
    }
    //获取姓名
    string getName(){
        return m_Name;
    }
    void setAge(int age){
        if(age < 0 || age > 150){
            m_Age = 0;
            cout<<"你这个老妖精!"<<endl;
            return;
        }
        m_Age = age;
    }
    int getAge(){
        return m_Age;
    }
};
int main(){
    Person p;
    p.setName("张三");
    cout<<p.getName()<<endl;
    p.setAge(1000);
    cout<<p.getAge()<<endl;
    return 0;
}
