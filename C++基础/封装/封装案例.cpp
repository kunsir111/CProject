#include<iostream>
using namespace std;

class Student{

public: //����Ȩ��

    //���е����Ժ���Ϊͳһ��Ϊ��Ա
    //���� ��Ա���� ��Ա����
    //��Ϊ ��Ա���� ��Ա����

    //����
    string m_Name;
    int m_id;


    //��Ϊ
    void showStudent(){
        cout<<"����: "<<m_Name<<"\tѧ�ţ�"<<m_id<<endl;
    }
    void setName(string name){
        m_Name = name;
    }
    void setId(int id){
        m_id = id;
    }
};

int main(){
    Student stu1, stu2;
    stu1.m_Name = "����";
    stu1.m_id = 1343;
    stu1.showStudent();
    stu2.setName("���");
    stu2.setId(123);
    stu2.showStudent();
    return 0;
}
