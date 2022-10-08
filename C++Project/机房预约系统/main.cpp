#include <iostream>
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "teacher.h"
#include "student.h"
#include "manager.h"

using namespace std;


//进入管理员子菜单页面
void managerMenu(Identity * &m){

    while(true){
        m->operMenu();
        int select = 0;
        manager* man = (manager*)m;
        //接收用户选择
        cin>>select;
        switch(select){
            case 1: //添加账号
                cout<<"添加账号"<<endl;
                man->addPerson();
                break;
            case 2: //查看账号
                cout<<"查看账号"<<endl;
                man->showPerson();
                break;
            case 3: //查看机房
                cout<<"查看机房"<<endl;
                man->showComputer();
                break;
            case 4: //清空预约
                cout<<"清空预约"<<endl;
                man->cleanFile();
                break;
            case 0: //注销登录
                cout<<"注销登录成功！"<<endl;
                delete m; //销毁堆区对象
                system("pause");
                system("cls");
                return;
            default:
                cout<<"请输入（0~4）的选项！"<<endl;
                system("pause");
                system("cls");
                break;
        }

    }
}

void studentMenu(Identity* & stu){

    student* s = (student*)stu;
    while(true){
        int select = 0;
        stu->operMenu();
        cin>>select;
        switch(select){
            case 1: //申请预约
                cout<<"申请预约"<<endl;
                s->applyOrder();
                break;
            case 2: // 查看我的预约
                cout<<"查看我的预约"<<endl;
                s->showMyOrder();
                break;
            case 3: // 查看所有预约
                cout<<"查看所有预约"<<endl;
                s->showAllOrder();
                break;
            case 4: // 取消预约
                cout<<"取消预约"<<endl;
                s->cancelOrder();
                break;
            case 0: //注销登录
                delete stu;
                cout<<"注销登录成功！"<<endl;
                system("pause");
                system("cls");
                return ;
            default:
                cout<<"请输入（0~4）的选项！"<<endl;
                system("pause");
                system("cls");
                break;

        }
    }
}

void teacherMenu(Identity * & tea){
    int select;
    while(true){
        tea->operMenu();
        teacher* t = (teacher*)tea;
        cin>>select;
        switch(select){
            case 1: //查看所有预约
                cout<<"查看所有预约"<<endl;
                t->showAllOrder();
                break;
            case 2: // 审核预约
                cout<<"审核预约"<<endl;
                t->validOrder();
                break;
            case 0:
                delete tea;
                cout<<"注销登录成功！"<<endl;
                system("pause");
                system("cls");
                return ;
            default:
                cout<<"请输入（0~2）的选项！"<<endl;
                system("pause");
                system("cls");
                break;
        }
    }
}

//登录的功能 参数1 操作文件名称，参数2 操作身份类型
void Login(string fileName, int type){
    Identity *person = NULL;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    //判断文件是否存在
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl;
        ifs.close();
        return;
    }

    //
    int id = 0;
    string name;
    string pwd;

    if(type == 1){ //学生身份
        cout<<"请输入你的学号："<<endl;
        cin>>id;
    } else if(type == 2){
        cout<<"请输入你的职工号："<<endl;
        cin>>id;
    }
    cout<<"请输入用户名："<<endl;
    cin>>name;
    cout<<"请输入密码："<<endl;
    cin>>pwd;

    if(type == 1){
        //学生身份验证
        int fId; //从文件中读取的ID号
        string fName;//从文件中获取的姓名
        string fPwd; //从文件中获取的密码
        while(ifs>>fId && ifs>>fName && ifs>>fPwd){
//            cout<<fId<<endl;
//            cout<<fName<<endl;
//            cout<<fPwd<<endl;
            if(id == fId && name == fName && pwd == fPwd){
                cout<<"学生登录成功！"<<endl;
                system("pause");
                system("cls");
                person = new student(id, name, pwd);
                //进入学生身份的子菜单
                studentMenu(person);

                return;
            }
        }

    } else if(type == 2){
        //教师身份验证
        int fId;
        string fName;
        string fPwd;
        while(ifs>>fId && ifs>>fName && ifs>>fPwd){
            if(fId == id && fName == name && fPwd == pwd){
                cout<<"教师登录成功！"<<endl;
                system("pause");
                system("cls");
                //进入教师身份子菜单
                person = new teacher(id, name, pwd);
                teacherMenu(person);

                return ;
            }
        }

    } else if(type == 3){
        //管理员身份验证
        string fName;
        string fPwd;
        while(ifs >> fName && ifs >> fPwd){
            if(name == fName && pwd == fPwd){
                cout<<"管理员登录成功"<<endl;
                system("pause");
                system("cls");
                person = new manager(name, pwd);
                managerMenu(person);

                return ;
            }
        }
    }

    cout<<"验证登录失败"<<endl;
    system("pause");
    system("cls");
    return ;

}

int main()
{
    int select = 0;

    while(true){
        cout<<"========================= 欢迎来到李安坤的机房预约系统===================="<<endl;
        cout<<endl<<"请输入您的身份"<<endl;
        cout<<"\t\t -----------------------------\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          1.学生代表         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          2.老    师         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          3.管 理 员         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          0.退    出         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t -----------------------------\n";
        cout<<"输入您的选择：";
        cin >> select;
        switch(select){
            case 1: //学生身份
                Login(STUDENT_FILE, select);
                break;
            case 2: //老师身份
                Login(TEACHER_FILE, select);
                break;
            case 3: //管理员身份
                Login(ADMIN_FILE, select);
                break;
            case 0: //退出系统
                cout << "欢迎下次使用"<<endl;
                system("pause");
                return 0;
                break;
            default:
                cout<<"输入有误，请重新输入！！！"<<endl;
                system("pause");
                system("cls");
                break;
        }
    }

    system("pause");
    return 0;
}
