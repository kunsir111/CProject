
#include<iostream>
using namespace std;

//�������ʹ�������
//1.�������������������������ͨ������ָ���ͷ��������
//2.���������û�ж������ݣ����Բ�дΪ��������������
//3.ӵ�д���������������Ҳ���ڳ�����
class Animal{
public:
    Animal(){
        cout<<"Animal ���캯������"<<endl;
    }
//    //�������������Խ�� ��ָ���ͷ��������ʱ���ɾ�������
//    virtual ~Animal(){
//        cout<<"Animal ��������������"<<endl;
//    }
    //��������
    virtual ~Animal() = 0;

    //���麯��
    virtual void speak() = 0;
};

Animal::~Animal(){
    cout<<"Animal ���� ������������"<<endl;
}

class Cat: public Animal{
public:
    Cat(string name){
        cout<<"Cat ���캯������"<<endl;
        m_Name = new string(name);
    }
    ~Cat(){
        if(m_Name != NULL){
            cout<<"Cat ������������"<<endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    virtual void speak(){
        cout<<*m_Name<<"Сè��˵��"<<endl;
    }
    string *m_Name;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal;
}

int main(){

    test01();
    return 0;
}

