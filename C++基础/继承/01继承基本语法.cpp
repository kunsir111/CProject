
#include<iostream>
using namespace std;

//�̳�ʵ��ҳ��

class BasePage{
public:
    void header(){
        cout <<"��ҳ�������Ρ���¼��ע��...(����ͷ��)"<< endl;
    }
    void footer(){
        cout <<"�������ġ�����������վ�ڵ�ͼ...(�����ײ�)"<< endl;
    }
    void left(){
        cout << "Java��Python��C++��...(���������б�)"<< endl;
    }
};

//�̳еĺô��������ظ��Ĵ���
//�﷨�� class ������: �̳з�ʽ ������{
//
//}
//����Ҳ��Ϊ������
//����Ҳ��Ϊ����

//Javaҳ��
class Java :public BasePage{

public:
    void content(){
        cout<<"Javaѧ����Ƶ"<<endl;
    }

};
//Pythonҳ��
class Python :public BasePage{

public:
    void content(){
        cout<<"Pythonѧ����Ƶ"<<endl;
    }

};
//C++ҳ��
class CPP :public BasePage{

public:
    void content(){
        cout<<"C++ѧ����Ƶ"<<endl;
    }

};

void test01(){
    Java java;
    java.header();
    java.footer();
    java.left();
    java.content();
    cout<<"===================================="<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout<<"===================================="<<endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
    cout<<"===================================="<<endl;
}

int main(){
    test01();
    return 0;
}
