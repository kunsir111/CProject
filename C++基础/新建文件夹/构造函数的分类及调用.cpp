#include<iostream>
using namespace std;

//1�����캯���ķ��༰����
//����
//  ���ղ������з���   �޲ι��� ��Ĭ�Ϲ��죩���вι���
//  �������ͷ���       ��ͨ����  ��������
class Person{
public:
    Person(){
        cout<<"Person ���޲ι��캯��"<<endl;
    }
    Person(int a){
        age = a;
        cout<<"Person ���вι��캯��"<<endl;
    }
    ~Person(){
        cout<<"Person ����������"<<endl;
    }
    //�������캯��
    Person(const Person &p){
        //������������ϵ��������Կ�����������
        age = p.age;
        cout<<"Person �Ŀ�������"<<endl;
    }
    int age;
};

void test01(){
    //1�����ŷ�
//    Person p1;
//    Person p2(2);
//    Person p3(p2);
    //ע������1
    //����Ĭ�Ϲ��캯��ʱ����Ҫ�ӣ���
    //��Ϊ Person p1() ��һ����������;
//    cout<<p2.age<<endl;
//    cout<<p3.age<<endl;
    //2����ʾ��
    Person p1;
    Person p2 = Person(10);
    Person p3 = Person(p2);
//    Person(10); //�������� �ص㣺��ǰ��ִ�н�����ϵͳ���������յ�����
    //3��=��ʽת����
    Person p4 = 10;
    Person p5 = p4;
}

int main(){
    test01();
    return 0;
}
