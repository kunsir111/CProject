#include<iostream>

using namespace std;

class Animal{
public:
    //�麯��
    virtual void speak(){
        cout<<"������˵��"<<endl;
    }
};

//è��
class Cat: public Animal{
public:
    void speak(){
        cout<<"Сè��˵��"<<endl;
    }
};

//����
class Dog: public Animal{
public:
    void speak(){
        cout<<"С����˵��"<<endl;
    }
};

//��ַ��󶨣��ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô��������Ͳ������,��Ҫ��

//��̬��̬��������
//1���м̳й�ϵ
//2��������д������麯��

//��̬��̬��ʹ��
//�����ָ������� ִ���������

void doSpeak(Animal &animal){
    animal.speak();
}

void test01(){
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02(){
    cout<<"sizeof animal = "<<sizeof(Animal)<<endl;
}

int main(){
//    test01();
    test02();
    return 0;
}
