
#include<iostream>
#include<fstream>
using namespace std;

//文本文件

void test01(){
    //1、创建流对象
    ofstream ofs;
    //2、指定打开方式
    ofs.open("test.txt", ios::out);
    //3、写内容
    ofs<<"姓名：张三"<<endl;
    ofs<<"性别：男"<<endl;
    ofs<<"年龄：18"<<endl;
    //4、关闭文件
    ofs.close();
}

void test02(){
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs<<"哈哈哈哈哈，王贤栋臭傻逼"<<endl;
    ofs.write("哈哈哈哈哈，王贤栋臭傻逼", sizeof("哈哈哈哈哈，王贤栋臭傻逼"));
    ofs.close();
}

int main(){
//    test01();
    test02();
    return 0;
}
