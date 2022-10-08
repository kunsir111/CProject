
#include<iostream>
using namespace std;

class C1{

    int m_A; //默认权限：私有
};

struct C2{

    int m_A; //默认权限：公共
};

int main(){
    //struct和class的区别
    //struct 默认权限是公共 public
    //class  默认权限是私有 private
//    C1 c1;
//    c1.m_A = 100;  //在struct中默认权限是私有，不可以访问
    C2 c2;
    c2.m_A = 100; //在struct中默认权限是公共，可以访问
    return 0;
}
