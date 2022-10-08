
#include<iostream>
using namespace std;

//函数调用运算符重载

//打印输出类
class MyPrint{

public:

    //重载函数调用运算符
    void operator()(string test){
        cout<<test<<endl;
    }
};

//仿函数非常灵活，没有固定的写法
void MyPrint02(string test){
    cout<<test<<endl;
}

void test01(){
    MyPrint myPrint;
    myPrint("Hello World!");

    MyPrint02("Hello World!");
}

//加法类

class MyAdd{
public:
    int operator()(int num1, int num2){
        return num1 + num2;
    }
};

void test02(){
    MyAdd myAdd;
    int res = myAdd(100, 100);
    cout<<"res: "<<res<<endl;

    //匿名函数对象
    cout<<MyAdd()(100, 100)<<endl;
}

int main(){
//    test01();
    test02();
    return 0;
}
