
//��ǳ���������Ծ������⣬Ҳ�ǳ�����һ����
//ǳ����:�򵥵ĸ�ֵ��������
//���:�ڶ������µ���ռ䣬���п�������
//�ܽ�:����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������

#include<iostream>
using namespace std;

//�����ǳ����
class Person{

public:

    Person(){
        cout<<"Person ���޲ι��캯������"<<endl;
    }
    Person(int age, int height){
        m_Age = age;
        m_Height = new int(height);
        cout<<"Person ���޲ι��캯������"<<endl;
    }
    Person(const Person &p){
        m_Age = p.m_Age;
        m_Height = new int(*p.m_Height);
        cout<<"Person �Ŀ������캯������"<<endl;
    }
    ~Person(){
        //�������룬���������������ͷ�
        if(m_Height != NULL){

            delete m_Height;
            m_Height = NULL; //��ֹ����Ұָ��
        }
        cout<<"Person ��������������"<<endl;
    }
    int m_Age;
    int *m_Height;
};

void test01(){
    Person p1(18, 170);
    cout<<"p1������Ϊ"<<p1.m_Age<<"���Ϊ��"<<*p1.m_Height<<endl;
    Person p2(p1);
    cout<<"p2������Ϊ"<<p2.m_Age<<"���Ϊ��"<<*p2.m_Height<<endl;
}

int main(){
    test01();
    return 0;
}
