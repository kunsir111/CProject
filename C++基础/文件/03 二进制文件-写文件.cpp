
#include<iostream>
#include<fstream>
using namespace std;

//二进制文件 写文件
class Person{
public:
    char m_Name[64]; //姓名
    int m_Age; //年龄

};

void test01(){
    //1、创建流对象
    ofstream ofs;
    //2、打开文件
    ofs.open("test.txt", ios::out|ios::binary);
    //3、写文件
    Person p = {"张三", 18};
    ofs.write( (const char *)&p, sizeof(p));

    ofs.close();
}

int main(){
    test01();
    return 0;
}
