
#include<iostream>
using namespace std;

//重载关系运算符

class Person{
public:
    Person(string name, int age){
        m_Name = name;
        m_Age = age;
    }
    bool operator==(Person &p){
        if(this->m_Name == p.m_Name && this->m_Age == p.m_Age){
            return true;
        }
        return false;
    }

    string m_Name;
    int m_Age;
};

void test01(){
    Person p1("Tom", 18);
    Person p2("Tm", 18);
    if(p1 == p2){
        cout<<"p1和p2相等"<<endl;
    } else {
        cout<<"p1和p2不相等"<<endl;
    }
}

int main(){
    test01();
    return 0;
}
