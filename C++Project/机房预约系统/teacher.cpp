
#include "teacher.h"
#include "orderFile.h"
#include <iostream>
#include <vector>

//Ĭ�Ϲ���
teacher::teacher(){
}

//�вι���
teacher::teacher(int empId, string name, string pwd){
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//����˵�
void teacher::operMenu(){
    cout<<"========================= ��ӭ"<<this->m_Name<<"��¼===================="<<endl;
    cout<<endl;
    cout<<"\t\t -----------------------------\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          1.�鿴����ԤԼ     |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          2.���ԤԼ         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          0.ע����¼         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t -----------------------------\n";
    cout<<"��������ѡ��";
}

//�鿴����ԤԼ
void teacher::showAllOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"��ԤԼ��¼"<<endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < r->m_Size; i++){
        cout<<"��"<<i<<"��ԤԼ��¼��";
        cout<<"ԤԼ���ڣ���"<<r->m_orderData[i]["date"]<<" ";
        cout<<"ʱ��Σ�"<<(r->m_orderData[i]["interval"] == "1"?"����": "����")<<" ";
        cout<<"ѧ�ţ�"<<r->m_orderData[i]["stuId"]<<" ";
        cout<<"������"<<r->m_orderData[i]["stuName"]<<" ";
        cout<<"������ţ�"<<r->m_orderData[i]["roomId"]<<" ";
        string status = "���״̬��";
        if(r->m_orderData[i]["status"] == "1"){
            status += "�����";
        } else if (r->m_orderData[i]["status"] == "2"){
            status += "ԤԼ�ɹ�";
        } else if (r->m_orderData[i]["status"] == "-1"){
            status += "ԤԼʧ�ܣ����δͨ��";
        } else {
            status += "ԤԼ��ȡ��";
        }
        cout<<status<<endl;
    }
    delete r;
    system("pause");
    system("cls");
}

//���ԤԼ
void teacher::validOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"��ԤԼ��¼"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"�����ԤԼ��¼���£�"<<endl;
    vector<int> vec;
    int index = 0;
    for(int i = 0; i < r->m_Size; i++){
        if(r->m_orderData[i]["status"] == "1"){
            vec.push_back(i);
            cout<<++index<<"��";
            cout<<"ԤԼ���ڣ���"<<r->m_orderData[i]["date"]<<" ";
            cout<<"ʱ��Σ�"<<(r->m_orderData[i]["interval"] == "1"?"����": "����")<<" ";
            cout<<"ѧ�ţ�"<<r->m_orderData[i]["stuId"]<<" ";
            cout<<"������"<<r->m_orderData[i]["stuName"]<<" ";
            cout<<"������ţ�"<<r->m_orderData[i]["roomId"]<<" ";
            string status = "���״̬�������";
            cout<<status<<endl;
        }
    }
    cout<<"��������˵�ԤԼ��¼��0������";
    int select = 0;
    int res = 0;
    while(true){
        cin>>select;
        if(select >= 0 && select <= vec.size()){
            if(select == 0){
                break;
            }
            cout<<"��������˽����"<<endl;
            cout<<"1��ͨ��"<<endl;
            cout<<"2����ͨ��"<<endl;
            cin>>res;

            if(res == 1){
                r->m_orderData[vec[select - 1]]["status"] = "2";
            } else {
                r->m_orderData[vec[select - 1]]["status"] = "-1";
            }
            r->updateOrder();
            cout<<"������"<<endl;
            break;

        }
        cout<<"������������������"<<endl;
    }
    delete r;
    system("pause");
    system("cls");
}
