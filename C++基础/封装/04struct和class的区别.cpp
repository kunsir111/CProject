
#include<iostream>
using namespace std;

class C1{

    int m_A; //Ĭ��Ȩ�ޣ�˽��
};

struct C2{

    int m_A; //Ĭ��Ȩ�ޣ�����
};

int main(){
    //struct��class������
    //struct Ĭ��Ȩ���ǹ��� public
    //class  Ĭ��Ȩ����˽�� private
//    C1 c1;
//    c1.m_A = 100;  //��struct��Ĭ��Ȩ����˽�У������Է���
    C2 c2;
    c2.m_A = 100; //��struct��Ĭ��Ȩ���ǹ��������Է���
    return 0;
}
