
#include<iostream>
#include<fstream>
using namespace std;

class Person{
public:
    char m_Name[64];
    int m_Age;
};

void test01(){
    ifstream ifs;
    ifs.open("test.txt", ios::in|ios::binary);
    if(!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    Person p;
    ifs.read( (char *)&p, sizeof(Person) );
    ifs.close();
    cout<<"姓名："<<p.m_Name<<endl;
    cout<<"年龄："<<p.m_Age<<endl;
}

int main(){
    test01();
    return 0;
}
