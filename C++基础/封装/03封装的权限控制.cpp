 #include<iostream>
using namespace std;

//����Ȩ��
//����
//����Ȩ�� public        ��Ա  ���ڿ��Է��ʣ�������Է���
//����Ȩ�� protected     ��Ա  ���ڿ��Է��ʣ����ⲻ���Է��� ���ӿ��Է��ʸ��׵�����
//˽��Ȩ�� private       ��Ա  ���ڿ��Է��ʣ����ⲻ���Է��� ���Ӳ����Է��ʸ��׵�����

class Person{

public:
    //����Ȩ��
    string m_Name;
protected:
    string m_Car;

private:
    int m_Password;

public:
    void func(){
        m_Name = "����";
        m_Car = "������";
        m_Password = 123456;
    }
    void printInfo(){
        cout<<m_Name<<" "<<m_Car<<" "<<m_Password<<endl;
    }
};

int main(){
    Person p1;
    p1.func();
    p1.printInfo();
    return 0;
}
