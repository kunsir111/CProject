
#include<iostream>
using namespace std;

class Base{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son: public Base{
public:
    int m_D;

};

void test01(){
    Son s;
    // ���������еķǾ�̬��Ա���Զ��ᱻ����̳���ȥ
    // ������˽�г�Ա���� �Ǳ������������ˣ���˷��ʲ���������ȷʵ���̳���ȥ��
    cout<<"size of Son = "<<sizeof(Son)<<endl;
}

int main(){
    test01();
    return 0;
}
