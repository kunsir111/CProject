
#include<iostream>
using namespace std;
//����ĳ�ʼ��������
//1�����캯�����г�ʼ��
class Person{
public:
    //1�����캯��
    //û�з���ֵ ����д��������
    //���캯����������
    //
    //
    Person(){
        cout<<"Person �Ĺ��캯������"<<endl;
    }
    //2����������
    ~Person(){
        cout<<"Person ����������"<<endl;
    }
};

void test01(){
    Person p;
}

int main(){
//    test01();
    Person p;
    return 0;
}
