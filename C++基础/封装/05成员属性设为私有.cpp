
#include<iostream>
using namespace std;

//��Ա��������Ϊ˽��
//1�������Լ����ƶ�дȨ��
//2������дȨ�ޣ����Լ�����ݵ���Ч��


//�������
class Person{
private:
    //����
    string m_Name;
    //����
    int m_Age;
    //����
    string m_Lover;

public:
    void setName(string name){
        m_Name = name;
    }
    //��ȡ����
    string getName(){
        return m_Name;
    }
    void setAge(int age){
        if(age < 0 || age > 150){
            m_Age = 0;
            cout<<"�����������!"<<endl;
            return;
        }
        m_Age = age;
    }
    int getAge(){
        return m_Age;
    }
};
int main(){
    Person p;
    p.setName("����");
    cout<<p.getName()<<endl;
    p.setAge(1000);
    cout<<p.getAge()<<endl;
    return 0;
}
