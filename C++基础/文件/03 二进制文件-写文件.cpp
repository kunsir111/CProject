
#include<iostream>
#include<fstream>
using namespace std;

//�������ļ� д�ļ�
class Person{
public:
    char m_Name[64]; //����
    int m_Age; //����

};

void test01(){
    //1������������
    ofstream ofs;
    //2�����ļ�
    ofs.open("test.txt", ios::out|ios::binary);
    //3��д�ļ�
    Person p = {"����", 18};
    ofs.write( (const char *)&p, sizeof(p));

    ofs.close();
}

int main(){
    test01();
    return 0;
}
