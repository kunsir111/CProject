
#include<iostream>
using namespace std;

//�����������������

//��ӡ�����
class MyPrint{

public:

    //���غ������������
    void operator()(string test){
        cout<<test<<endl;
    }
};

//�º����ǳ���û�й̶���д��
void MyPrint02(string test){
    cout<<test<<endl;
}

void test01(){
    MyPrint myPrint;
    myPrint("Hello World!");

    MyPrint02("Hello World!");
}

//�ӷ���

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

    //������������
    cout<<MyAdd()(100, 100)<<endl;
}

int main(){
//    test01();
    test02();
    return 0;
}
