//��̬��Ա����
//���ж�����ͬһ������
//��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
#include<iostream>
using namespace std;
class Person{
public:
    //��̬��Ա����
    static void func(){
        m_A = 100; //
        m_B = 200;
        cout<<"static void func����"<<endl;
    }
    static int m_A; //��̬��Ա����
    int m_B; //�Ǿ�̬��Ա����
private:
    static void func2(){
    }
};
void test01(){
    //1��ͨ���������
    Person p;
    p.func();
    //2��ͨ����������
    Person::func();

//    Person::func2(); //��̬��Ա����Ҳ�з���Ȩ��
}
int Person::m_A = 0;
int main(){
    test01();
    return 0;
}
