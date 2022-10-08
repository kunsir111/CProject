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

//有参构造
manager::manager(string name, string pwd){
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->initVector();
}

//菜单构造
void manager::operMenu(){
    cout<<"========================= 欢迎来管理员"<<this->m_Name<<"登录===================="<<endl;
    cout<<endl;
    cout<<"\t\t -----------------------------\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          1.添加账号         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          2.查看账号         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          3.查看机房         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          4.清空预约         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          0.注销登录         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t -----------------------------\n";
    cout<<"输入您的选择：";
}

//添加账号
void manager::addPerson(){
    cout<<"请输入添加账号的类型"<<endl;
    cout<<"1、添加学生"<<endl;
    cout<<"2、添加教师"<<endl;
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
            cout<<"请输入正确选项（1 or 2）："<<endl;
            cin>>select;
        }
    }
    ofs.open(fileName, ios::out|ios::app);
    if(select == 1){
        cout<<"请输入学号：";
    } else {
        cout<<"请输入职工号：";
    }

    int id;
    string name;
    string pwd;
    cin>>id;
    while(true){
        if(this->checkRepeat(id, select)){
            if(select == 1){
                cout<<"学号已经存在，请重新输入："<<endl;
            }else if(select == 2) {
                cout<<"职工号已经存在，请重新输入："<<endl;
            }
            cin>>id;
        } else {
            break;
        }
    }

    cout<<"请输入姓名：";
    cin>>name;

    cout<<"请输入密码：";
    cin>>pwd;

    ofs << id << " " << name << " " << pwd << endl;
    cout<<"添加成功"<<endl;

    this->initVector();

    system("pause");
    system("cls");

    ofs.close();
}

void printStudent(student & s){
    cout<<"学号："<<s.m_Id<<"，姓名："<<s.m_Name<<"，密码："<<s.m_Pwd<<endl;
}

void printTeacher(teacher & t){
    cout<<"职工号："<<t.m_EmpId<<"，姓名："<<t.m_Name<<"，密码："<<t.m_Pwd<<endl;
}

void printComputerRoom(computerRoom & c){
    cout<<"机房号："<<c.m_ComId<<"，剩余数量："<<c.m_MaxNum<<endl;
}

//查看账号
void manager::showPerson(){
    cout<<"请输入查看学生或教师信息："<<endl;
    cout<<"1、查看学生信息"<<endl;
    cout<<"2、查看教师信息"<<endl;
    int select = 0;
    cin>>select;
    ifstream ifs;
    string fileName;
    string tip;
    while(true){
        if(select == 1){
            fileName = STUDENT_FILE;
            tip = "学号";
            break;
        } else if(select == 2){
            fileName = TEACHER_FILE;
            tip = "职工号";
            break;
        } else{
            cout<<"输入有误，请重新输入"<<endl;
            cin>>select;
        }
    }
    ifs.open(fileName, ios::in);
    int id;
    string name;
    string pwd;
    if(select == 1){
        cout<<"全部学生信息"<<endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    } else {
        cout<<"全部教师信息"<<endl;
        for_each(vTea.begin(), vTea.end(), printTeacher);
    }


    system("pause");
    system("cls");
}

//查看机房信息
void manager::showComputer(){
    cout<<"全部机房信息"<<endl;
    for_each(vCom.begin(), vCom.end(), printComputerRoom);
    system("pause");
    system("cls");
}

//清空预约记录
void manager::cleanFile(){

    string s;
    cout<<"确认是否清空(y/n)"<<endl;
    cin>>s;
    if(s == "y"){
        ofstream ofs(ORDER_FILE, ios::trunc);
        ofs.close();
        cout<<"清空成功"<<endl;
    } else {
        cout<<"未清空"<<endl;
    }
    system("pause");
    system("cls");
}


void manager::initVector(){
    vStu.clear();
    vTea.clear();
    ifstream ifs;

    //读取信息 学生
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"文件读取失败！"<<endl;
        return ;
    }

    student s;
    while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd){
        vStu.push_back(s);
    }
    cout<<"当前学生数量为："<<vStu.size()<<endl;
    ifs.close();

    //读取信息 教师
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"文件读取失败！"<<endl;
        return ;
    }
    teacher tea;
    while(ifs >> tea.m_EmpId && ifs >> tea.m_Name && ifs >> tea.m_Pwd){
        vTea.push_back(tea);
    }
    cout<<"当前老师数量为："<<vTea.size()<<endl;
    ifs.close();

    //读取信息 机房
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"文件打开失败！"<<endl;
        return;
    }
    computerRoom com;
    while(ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        vCom.push_back(com);
    }
    cout<<"当前机房数量为："<<vCom.size()<<endl;
    ifs.close();
}

bool manager::checkRepeat(int id, int type){
    if(type == 1){
        //检测学生
        for(vector<student>::iterator it = vStu.begin(); it != vStu.end(); it++){
            if(id == it->m_Id){
                return true;
            }
        }
    } else if (type == 2){
        //检测教师
        for(vector<teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if(id == it->m_EmpId){
                return true;
            }
        }
    }
}
