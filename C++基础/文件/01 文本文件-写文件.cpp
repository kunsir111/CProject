
#include<iostream>
#include<fstream>
using namespace std;

//�ı��ļ�

void test01(){
    //1������������
    ofstream ofs;
    //2��ָ���򿪷�ʽ
    ofs.open("test.txt", ios::out);
    //3��д����
    ofs<<"����������"<<endl;
    ofs<<"�Ա���"<<endl;
    ofs<<"���䣺18"<<endl;
    //4���ر��ļ�
    ofs.close();
}

void test02(){
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs<<"���������������Ͷ���ɵ��"<<endl;
    ofs.write("���������������Ͷ���ɵ��", sizeof("���������������Ͷ���ɵ��"));
    ofs.close();
}

int main(){
//    test01();
    test02();
    return 0;
}
