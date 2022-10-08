
#include "teacher.h"
#include "orderFile.h"
#include <iostream>
#include <vector>

//默认构造
teacher::teacher(){
}

//有参构造
teacher::teacher(int empId, string name, string pwd){
    this->m_EmpId = empId;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

//界面菜单
void teacher::operMenu(){
    cout<<"========================= 欢迎"<<this->m_Name<<"登录===================="<<endl;
    cout<<endl;
    cout<<"\t\t -----------------------------\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          1.查看所有预约     |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          2.审核预约         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          0.注销登录         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t -----------------------------\n";
    cout<<"输入您的选择：";
}

//查看所有预约
void teacher::showAllOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"无预约记录"<<endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < r->m_Size; i++){
        cout<<"第"<<i<<"条预约记录：";
        cout<<"预约日期：周"<<r->m_orderData[i]["date"]<<" ";
        cout<<"时间段："<<(r->m_orderData[i]["interval"] == "1"?"上午": "下午")<<" ";
        cout<<"学号："<<r->m_orderData[i]["stuId"]<<" ";
        cout<<"姓名："<<r->m_orderData[i]["stuName"]<<" ";
        cout<<"机房编号："<<r->m_orderData[i]["roomId"]<<" ";
        string status = "审核状态：";
        if(r->m_orderData[i]["status"] == "1"){
            status += "审核中";
        } else if (r->m_orderData[i]["status"] == "2"){
            status += "预约成功";
        } else if (r->m_orderData[i]["status"] == "-1"){
            status += "预约失败，审核未通过";
        } else {
            status += "预约已取消";
        }
        cout<<status<<endl;
    }
    delete r;
    system("pause");
    system("cls");
}

//审核预约
void teacher::validOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"无预约记录"<<endl;
        system("pause");
        system("cls");
        return;
    }
    cout<<"待审核预约记录如下："<<endl;
    vector<int> vec;
    int index = 0;
    for(int i = 0; i < r->m_Size; i++){
        if(r->m_orderData[i]["status"] == "1"){
            vec.push_back(i);
            cout<<++index<<"、";
            cout<<"预约日期：周"<<r->m_orderData[i]["date"]<<" ";
            cout<<"时间段："<<(r->m_orderData[i]["interval"] == "1"?"上午": "下午")<<" ";
            cout<<"学号："<<r->m_orderData[i]["stuId"]<<" ";
            cout<<"姓名："<<r->m_orderData[i]["stuName"]<<" ";
            cout<<"机房编号："<<r->m_orderData[i]["roomId"]<<" ";
            string status = "审核状态：审核中";
            cout<<status<<endl;
        }
    }
    cout<<"请输入审核的预约记录，0代表返回";
    int select = 0;
    int res = 0;
    while(true){
        cin>>select;
        if(select >= 0 && select <= vec.size()){
            if(select == 0){
                break;
            }
            cout<<"请输入审核结果："<<endl;
            cout<<"1、通过"<<endl;
            cout<<"2、不通过"<<endl;
            cin>>res;

            if(res == 1){
                r->m_orderData[vec[select - 1]]["status"] = "2";
            } else {
                r->m_orderData[vec[select - 1]]["status"] = "-1";
            }
            r->updateOrder();
            cout<<"审核完毕"<<endl;
            break;

        }
        cout<<"输入有误，请重新输入"<<endl;
    }
    delete r;
    system("pause");
    system("cls");
}
