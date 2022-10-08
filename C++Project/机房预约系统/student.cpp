
#include "student.h"
#include <fstream>
#include "globalFile.h"
#include "computerRoom.h"
#include "orderFile.h"
#include<map>
#include<string>
#include<vector>

//Ĭ�Ϲ���
student::student(){
}

//�вι���
student::student(int id, string name, string pwd){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    computerRoom com;
    while(ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        //����ȡ����Ϣ����������
        vCom.push_back(com);
    }

    cout<<"���л�������Ϊ��"<<vCom.size();
    ifs.close();

}

//�˵�����
void student::operMenu(){
    cout<<"========================= ��ӭ"<<this->m_Name<<"��¼===================="<<endl;
    cout<<endl;
    cout<<"\t\t -----------------------------\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          1.����ԤԼ         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          2.�鿴�ҵ�ԤԼ     |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          3.�鿴����ԤԼ     |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          4.ȡ��ԤԼ         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          0.ע����¼         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t -----------------------------\n";
    cout<<"��������ѡ��";
}

//����ԤԼ
void student::applyOrder(){
    cout<<"��������ʱ��Ϊ��һ������"<<endl;
    cout<<"����������ԤԼ��ʱ�䣺"<<endl;
    cout<<"1����һ"<<endl;
    cout<<"2���ܶ�"<<endl;
    cout<<"3������"<<endl;
    cout<<"4������"<<endl;
    cout<<"5������"<<endl;

    int date = 0;
    int interval = 0;
    int room = 0;
    while(true){
        cin>>date;
        if(date >= 1 && date <= 5){
            break;
        }
        cout<<"������������������"<<endl;
    }
    cout<<"����������ԤԼʱ��Σ�"<<endl;
    cout<<"1������"<<endl;
    cout<<"2������"<<endl;
    while(true){
        cin>>interval;
        if(interval == 1 || interval == 2){
            break;
        }
        cout<<"������������������"<<endl;
    }

    cout<<"��ѡ�������"<<endl;

    for(int i = 0; i < vCom.size(); i++){
        cout<<vCom[i].m_ComId<<"�Ż�������Ϊ��"<<vCom[i].m_MaxNum<<endl;
    }
    while(true){
        cin>>room;
        if(room >= 1 && room <= vCom.size()){
            break;
        }
        cout<<"������������������"<<endl;
    }
    cout<<"ԤԼ�ɹ��������"<<endl;

    ofstream ofs;

    ofs.open(ORDER_FILE, ios::app);

    ofs<<"date:"<<date<<" ";
    ofs<<"interval:"<<interval<<" ";
    ofs<<"stuId:"<<this->m_Id<<" ";
    ofs<<"stuName:"<<this->m_Name<<" ";
    ofs<<"roomId:"<<room<<" ";
    ofs<<"status:"<<1<<endl;

    ofs.close();

    system("pause");
    system("cls");

}

//�鿴����ԤԼ
void student::showMyOrder(){
    orderFile of;
    if(of.m_Size == 0){
        cout<<"��ԤԼ��¼"<<endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < of.m_Size; i++){
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){ //�ҵ�����ԤԼ
            cout<<"ԤԼ���ڣ���"<<of.m_orderData[i]["date"] << " ";
            cout<<"ʱ��Σ�"<<(of.m_orderData[i]["interval"] == "1"?"����": "����") << " ";
            cout<<"������"<<of.m_orderData[i]["roomId"] << " ";
            string status = "״̬��";
            if(of.m_orderData[i]["status"] == "1"){
                status += "�����";
            } else if(of.m_orderData[i]["status"] == "2"){
                status += "ԤԼ�ɹ�";
            } else if(of.m_orderData[i]["status"] == "-1"){
                status += "ԤԼʧ��";
            } else {
                status += "ԤԼ��ȡ��";
            }
            cout<<status<<endl;

        }
    }
    system("pause");
    system("cls");

}

//�鿴����ԤԼ
void student::showAllOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"�޼�¼"<<endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < r->m_Size; i++){
        cout<<"��"<<i<<"��ԤԼ��";
        cout<<"ԤԼ���ڣ���"<<r->m_orderData[i]["date"]<<" ";
        cout<<"ʱ��Σ�"<< (r->m_orderData[i]["interval"] == "1" ? "����" : "����")<<" ";
        cout<<"ѧ�ţ�"<< r->m_orderData[i]["stuId"]<<" ";
        cout<<"������"<<r->m_orderData[i]["stuName"]<<" ";
        cout<<"������ţ�"<<r->m_orderData[i]["roomId"]<<" ";
        string status = "���״̬��";
        if(r->m_orderData[i]["status"] == "1"){
            status += "�����";
        } else if(r->m_orderData[i]["status"] == "2"){
            status += "ԤԼ�ɹ�";
        } else if(r->m_orderData[i]["status"] == "-1"){
            status += "ԤԼʧ�ܣ����δͨ��";
        } else if(r->m_orderData[i]["status"] == "0"){
            status += "ԤԼ��ȡ��";
        }
        cout<<status<<endl;
    }
    system("pause");
    system("cls");
    delete r;
}

//ȡ��ԤԼ
void student::cancelOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"��ԤԼ��¼��"<<endl;
        system("pause");
        system("cls");
        return ;
    }
    cout<<"����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼��ţ�"<<endl;
    int select = 0;
    int index = 1;
    vector<int> vec;
    for(int i = 0; i < r->m_Size; i++){
        if(this->m_Id == atoi(r->m_orderData[i]["stuId"].c_str())){
            if(r->m_orderData[i]["status"] == "1" || r->m_orderData[i]["status"] == "2"){
                cout<<index++<<"��";
                vec.push_back(i);
                cout<<"ԤԼ���ڣ���"<<r->m_orderData[i]["date"] << " ";
                cout<<"ʱ��Σ�"<<(r->m_orderData[i]["interval"] == "1"?"����": "����") << " ";
                cout<<"�����ţ�"<<r->m_orderData[i]["roomId"] << " ";
                string status = "״̬��";
                if(r->m_orderData[i]["status"] == "1"){
                    status += "�����";
                } else if(r->m_orderData[i]["status"] == "2"){
                    status += "ԤԼ�ɹ�";
                }
                cout<<status<<endl;
            }
        }
    }
    cout<<"������ȡ���ļ�¼��0�����أ�";

    while(true){
        cin>>select;
        if(select >= 0 && select <= vec.size()){
            if(select == 0){
                break;
            }
            r->m_orderData[vec[select - 1]]["status"] = "0";
            r->updateOrder();
            cout<<"��ȡ��ԤԼ"<<endl;
            break;
        }
        cout<<"�����������������룡"<<endl;
    }
    system("pause");
    system("cls");
    delete r;
}

