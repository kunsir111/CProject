#include <iostream>
#include "Identity.h"
#include <fstream>
#include <string>
#include "globalFile.h"
#include "teacher.h"
#include "student.h"
#include "manager.h"

using namespace std;


//�������Ա�Ӳ˵�ҳ��
void managerMenu(Identity * &m){

    while(true){
        m->operMenu();
        int select = 0;
        manager* man = (manager*)m;
        //�����û�ѡ��
        cin>>select;
        switch(select){
            case 1: //����˺�
                cout<<"����˺�"<<endl;
                man->addPerson();
                break;
            case 2: //�鿴�˺�
                cout<<"�鿴�˺�"<<endl;
                man->showPerson();
                break;
            case 3: //�鿴����
                cout<<"�鿴����"<<endl;
                man->showComputer();
                break;
            case 4: //���ԤԼ
                cout<<"���ԤԼ"<<endl;
                man->cleanFile();
                break;
            case 0: //ע����¼
                cout<<"ע����¼�ɹ���"<<endl;
                delete m; //���ٶ�������
                system("pause");
                system("cls");
                return;
            default:
                cout<<"�����루0~4����ѡ�"<<endl;
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
            case 1: //����ԤԼ
                cout<<"����ԤԼ"<<endl;
                s->applyOrder();
                break;
            case 2: // �鿴�ҵ�ԤԼ
                cout<<"�鿴�ҵ�ԤԼ"<<endl;
                s->showMyOrder();
                break;
            case 3: // �鿴����ԤԼ
                cout<<"�鿴����ԤԼ"<<endl;
                s->showAllOrder();
                break;
            case 4: // ȡ��ԤԼ
                cout<<"ȡ��ԤԼ"<<endl;
                s->cancelOrder();
                break;
            case 0: //ע����¼
                delete stu;
                cout<<"ע����¼�ɹ���"<<endl;
                system("pause");
                system("cls");
                return ;
            default:
                cout<<"�����루0~4����ѡ�"<<endl;
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
            case 1: //�鿴����ԤԼ
                cout<<"�鿴����ԤԼ"<<endl;
                t->showAllOrder();
                break;
            case 2: // ���ԤԼ
                cout<<"���ԤԼ"<<endl;
                t->validOrder();
                break;
            case 0:
                delete tea;
                cout<<"ע����¼�ɹ���"<<endl;
                system("pause");
                system("cls");
                return ;
            default:
                cout<<"�����루0~2����ѡ�"<<endl;
                system("pause");
                system("cls");
                break;
        }
    }
}

//��¼�Ĺ��� ����1 �����ļ����ƣ�����2 �����������
void Login(string fileName, int type){
    Identity *person = NULL;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    //�ж��ļ��Ƿ����
    if(!ifs.is_open()){
        cout<<"�ļ�������"<<endl;
        ifs.close();
        return;
    }

    //
    int id = 0;
    string name;
    string pwd;

    if(type == 1){ //ѧ�����
        cout<<"���������ѧ�ţ�"<<endl;
        cin>>id;
    } else if(type == 2){
        cout<<"���������ְ���ţ�"<<endl;
        cin>>id;
    }
    cout<<"�������û�����"<<endl;
    cin>>name;
    cout<<"���������룺"<<endl;
    cin>>pwd;

    if(type == 1){
        //ѧ�������֤
        int fId; //���ļ��ж�ȡ��ID��
        string fName;//���ļ��л�ȡ������
        string fPwd; //���ļ��л�ȡ������
        while(ifs>>fId && ifs>>fName && ifs>>fPwd){
//            cout<<fId<<endl;
//            cout<<fName<<endl;
//            cout<<fPwd<<endl;
            if(id == fId && name == fName && pwd == fPwd){
                cout<<"ѧ����¼�ɹ���"<<endl;
                system("pause");
                system("cls");
                person = new student(id, name, pwd);
                //����ѧ����ݵ��Ӳ˵�
                studentMenu(person);

                return;
            }
        }

    } else if(type == 2){
        //��ʦ�����֤
        int fId;
        string fName;
        string fPwd;
        while(ifs>>fId && ifs>>fName && ifs>>fPwd){
            if(fId == id && fName == name && fPwd == pwd){
                cout<<"��ʦ��¼�ɹ���"<<endl;
                system("pause");
                system("cls");
                //�����ʦ����Ӳ˵�
                person = new teacher(id, name, pwd);
                teacherMenu(person);

                return ;
            }
        }

    } else if(type == 3){
        //����Ա�����֤
        string fName;
        string fPwd;
        while(ifs >> fName && ifs >> fPwd){
            if(name == fName && pwd == fPwd){
                cout<<"����Ա��¼�ɹ�"<<endl;
                system("pause");
                system("cls");
                person = new manager(name, pwd);
                managerMenu(person);

                return ;
            }
        }
    }

    cout<<"��֤��¼ʧ��"<<endl;
    system("pause");
    system("cls");
    return ;

}

int main()
{
    int select = 0;

    while(true){
        cout<<"========================= ��ӭ��������Ļ���ԤԼϵͳ===================="<<endl;
        cout<<endl<<"�������������"<<endl;
        cout<<"\t\t -----------------------------\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          1.ѧ������         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          2.��    ʦ         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          3.�� �� Ա         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t|          0.��    ��         |\n";
        cout<<"\t\t|                             |\n";
        cout<<"\t\t -----------------------------\n";
        cout<<"��������ѡ��";
        cin >> select;
        switch(select){
            case 1: //ѧ�����
                Login(STUDENT_FILE, select);
                break;
            case 2: //��ʦ���
                Login(TEACHER_FILE, select);
                break;
            case 3: //����Ա���
                Login(ADMIN_FILE, select);
                break;
            case 0: //�˳�ϵͳ
                cout << "��ӭ�´�ʹ��"<<endl;
                system("pause");
                return 0;
                break;
            default:
                cout<<"�����������������룡����"<<endl;
                system("pause");
                system("cls");
                break;
        }
    }

    system("pause");
    return 0;
}
