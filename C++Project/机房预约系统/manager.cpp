#include <iostream>
#include <fstream>
#include "manager.h"
#include "globalFile.h"
#include "computerRoom.h"
#include <algorithm>
using namespace std;


manager::manager(){
    this->initVector();
}

//�вι���
manager::manager(string name, string pwd){
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->initVector();
}

//�˵�����
void manager::operMenu(){
    cout<<"========================= ��ӭ������Ա"<<this->m_Name<<"��¼===================="<<endl;
    cout<<endl;
    cout<<"\t\t -----------------------------\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          1.����˺�         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          2.�鿴�˺�         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          3.�鿴����         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          4.���ԤԼ         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          0.ע����¼         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t -----------------------------\n";
    cout<<"��������ѡ��";
}

//����˺�
void manager::addPerson(){
    cout<<"����������˺ŵ�����"<<endl;
    cout<<"1�����ѧ��"<<endl;
    cout<<"2����ӽ�ʦ"<<endl;
    int select = 0;
    cin>>select;
    ofstream ofs;
    string fileName;
    while(true){
        if(select == 1){
            fileName = STUDENT_FILE;
            break;
        } else if(select == 2){
            fileName = TEACHER_FILE;
            break;
        } else {
            cout<<"��������ȷѡ�1 or 2����"<<endl;
            cin>>select;
        }
    }
    ofs.open(fileName, ios::out|ios::app);
    if(select == 1){
        cout<<"������ѧ�ţ�";
    } else {
        cout<<"������ְ���ţ�";
    }

    int id;
    string name;
    string pwd;
    cin>>id;
    while(true){
        if(this->checkRepeat(id, select)){
            if(select == 1){
                cout<<"ѧ���Ѿ����ڣ����������룺"<<endl;
            }else if(select == 2) {
                cout<<"ְ�����Ѿ����ڣ����������룺"<<endl;
            }
            cin>>id;
        } else {
            break;
        }
    }

    cout<<"������������";
    cin>>name;

    cout<<"���������룺";
    cin>>pwd;

    ofs << id << " " << name << " " << pwd << endl;
    cout<<"��ӳɹ�"<<endl;

    this->initVector();

    system("pause");
    system("cls");

    ofs.close();
}

void printStudent(student & s){
    cout<<"ѧ�ţ�"<<s.m_Id<<"��������"<<s.m_Name<<"�����룺"<<s.m_Pwd<<endl;
}

void printTeacher(teacher & t){
    cout<<"ְ���ţ�"<<t.m_EmpId<<"��������"<<t.m_Name<<"�����룺"<<t.m_Pwd<<endl;
}

void printComputerRoom(computerRoom & c){
    cout<<"�����ţ�"<<c.m_ComId<<"��ʣ��������"<<c.m_MaxNum<<endl;
}

//�鿴�˺�
void manager::showPerson(){
    cout<<"������鿴ѧ�����ʦ��Ϣ��"<<endl;
    cout<<"1���鿴ѧ����Ϣ"<<endl;
    cout<<"2���鿴��ʦ��Ϣ"<<endl;
    int select = 0;
    cin>>select;
    ifstream ifs;
    string fileName;
    string tip;
    while(true){
        if(select == 1){
            fileName = STUDENT_FILE;
            tip = "ѧ��";
            break;
        } else if(select == 2){
            fileName = TEACHER_FILE;
            tip = "ְ����";
            break;
        } else{
            cout<<"������������������"<<endl;
            cin>>select;
        }
    }
    ifs.open(fileName, ios::in);
    int id;
    string name;
    string pwd;
    if(select == 1){
        cout<<"ȫ��ѧ����Ϣ"<<endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    } else {
        cout<<"ȫ����ʦ��Ϣ"<<endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }


    system("pause");
    system("cls");
}

//�鿴������Ϣ
void manager::showComputer(){
    cout<<"ȫ��������Ϣ"<<endl;
    for_each(vCom.begin(), vCom.end(), printComputerRoom);
    system("pause");
    system("cls");
}

//���ԤԼ��¼
void manager::cleanFile(){

    string s;
    cout<<"ȷ���Ƿ����(y/n)"<<endl;
    cin>>s;
    if(s == "y"){
        ofstream ofs(ORDER_FILE, ios::trunc);
        ofs.close();
        cout<<"��ճɹ�"<<endl;
    } else {
        cout<<"δ���"<<endl;
    }
    system("pause");
    system("cls");
}


void manager::initVector(){
    vStu.clear();
    vTea.clear();
    ifstream ifs;

    //��ȡ��Ϣ ѧ��
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"�ļ���ȡʧ�ܣ�"<<endl;
        return ;
    }

    student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd){
        vStu.push_back(s);
    }
    cout<<"��ǰѧ������Ϊ��"<<vStu.size()<<endl;
    ifs.close();

    //��ȡ��Ϣ ��ʦ
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"�ļ���ȡʧ�ܣ�"<<endl;
        return ;
    }
    teacher tea;
    while(ifs >> tea.m_EmpId && ifs >> tea.m_Name && ifs >> tea.m_Pwd){
        vTea.push_back(tea);
    }
    cout<<"��ǰ��ʦ����Ϊ��"<<vTea.size()<<endl;
    ifs.close();

    //��ȡ��Ϣ ����
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"�ļ���ʧ�ܣ�"<<endl;
        return;
    }
    computerRoom com;
    while(ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        vCom.push_back(com);
    }
    cout<<"��ǰ��������Ϊ��"<<vCom.size()<<endl;
    ifs.close();
}

bool manager::checkRepeat(int id, int type){
    if(type == 1){
        //���ѧ��
        for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++){
            if(id == it->m_Id){
                return true;
            }
        }
    } else if (type == 2){
        //����ʦ
        for(vector<teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if(id == it->m_EmpId){
                return true;
            }
        }
    }
}
