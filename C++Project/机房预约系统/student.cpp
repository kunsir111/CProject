
#include "student.h"
#include <fstream>
#include "globalFile.h"
#include "computerRoom.h"
#include "orderFile.h"
#include<map>
#include<string>
#include<vector>

//默认构造
student::student(){
}

//有参构造
student::student(int id, string name, string pwd){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    computerRoom com;
    while(ifs >> com.m_ComId && ifs >> com.m_MaxNum){
        //将读取的信息放入容器中
        vCom.push_back(com);
    }

    cout<<"所有机房数量为："<<vCom.size();
    ifs.close();

}

//菜单界面
void student::operMenu(){
    cout<<"========================= 欢迎"<<this->m_Name<<"登录===================="<<endl;
    cout<<endl;
    cout<<"\t\t -----------------------------\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          1.申请预约         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          2.查看我的预约     |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          3.查看所有预约     |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          4.取消预约         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t|          0.注销登录         |\n";
    cout<<"\t\t|                             |\n";
    cout<<"\t\t -----------------------------\n";
    cout<<"输入您的选择：";
}

//申请预约
void student::applyOrder(){
    cout<<"机房开放时间为周一至周五"<<endl;
    cout<<"请输入申请预约的时间："<<endl;
    cout<<"1、周一"<<endl;
    cout<<"2、周二"<<endl;
    cout<<"3、周三"<<endl;
    cout<<"4、周四"<<endl;
    cout<<"5、周五"<<endl;

    int date = 0;
    int interval = 0;
    int room = 0;
    while(true){
        cin>>date;
        if(date >= 1 && date <= 5){
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;
    }
    cout<<"请输入申请预约时间段："<<endl;
    cout<<"1、上午"<<endl;
    cout<<"2、下午"<<endl;
    while(true){
        cin>>interval;
        if(interval == 1 || interval == 2){
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;
    }

    cout<<"请选择机房："<<endl;

    for(int i = 0; i < vCom.size(); i++){
        cout<<vCom[i].m_ComId<<"号机房容量为："<<vCom[i].m_MaxNum<<endl;
    }
    while(true){
        cin>>room;
        if(room >= 1 && room <= vCom.size()){
            break;
        }
        cout<<"输入有误，请重新输入"<<endl;
    }
    cout<<"预约成功，审核中"<<endl;

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

//查看自身预约
void student::showMyOrder(){
    orderFile of;
    if(of.m_Size == 0){
        cout<<"无预约记录"<<endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < of.m_Size; i++){
        if(this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str())){ //找到自身预约
            cout<<"预约日期：周"<<of.m_orderData[i]["date"] << " ";
            cout<<"时间段："<<(of.m_orderData[i]["interval"] == "1"?"上午": "下午") << " ";
            cout<<"机房号"<<of.m_orderData[i]["roomId"] << " ";
            string status = "状态：";
            if(of.m_orderData[i]["status"] == "1"){
                status += "审核中";
            } else if(of.m_orderData[i]["status"] == "2"){
                status += "预约成功";
            } else if(of.m_orderData[i]["status"] == "-1"){
                status += "预约失败";
            } else {
                status += "预约已取消";
            }
            cout<<status<<endl;

        }
    }
    system("pause");
    system("cls");

}

//查看所有预约
void student::showAllOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"无记录"<<endl;
        system("pause");
        system("cls");
        return;
    }
    for(int i = 0; i < r->m_Size; i++){
        cout<<"第"<<i<<"条预约：";
        cout<<"预约日期：周"<<r->m_orderData[i]["date"]<<" ";
        cout<<"时间段："<< (r->m_orderData[i]["interval"] == "1" ? "上午" : "下午")<<" ";
        cout<<"学号："<< r->m_orderData[i]["stuId"]<<" ";
        cout<<"姓名："<<r->m_orderData[i]["stuName"]<<" ";
        cout<<"机房编号："<<r->m_orderData[i]["roomId"]<<" ";
        string status = "审核状态：";
        if(r->m_orderData[i]["status"] == "1"){
            status += "审核中";
        } else if(r->m_orderData[i]["status"] == "2"){
            status += "预约成功";
        } else if(r->m_orderData[i]["status"] == "-1"){
            status += "预约失败，审核未通过";
        } else if(r->m_orderData[i]["status"] == "0"){
            status += "预约已取消";
        }
        cout<<status<<endl;
    }
    system("pause");
    system("cls");
    delete r;
}

//取消预约
void student::cancelOrder(){
    orderFile *r = new orderFile();
    if(r->m_Size == 0){
        cout<<"无预约记录！"<<endl;
        system("pause");
        system("cls");
        return ;
    }
    cout<<"审核中或预约成功的记录可以取消，请输入取消的记录编号："<<endl;
    int select = 0;
    int index = 1;
    vector<int> vec;
    for(int i = 0; i < r->m_Size; i++){
        if(this->m_Id == atoi(r->m_orderData[i]["stuId"].c_str())){
            if(r->m_orderData[i]["status"] == "1" || r->m_orderData[i]["status"] == "2"){
                cout<<index++<<"、";
                vec.push_back(i);
                cout<<"预约日期：周"<<r->m_orderData[i]["date"] << " ";
                cout<<"时间段："<<(r->m_orderData[i]["interval"] == "1"?"上午": "下午") << " ";
                cout<<"机房号："<<r->m_orderData[i]["roomId"] << " ";
                string status = "状态：";
                if(r->m_orderData[i]["status"] == "1"){
                    status += "审核中";
                } else if(r->m_orderData[i]["status"] == "2"){
                    status += "预约成功";
                }
                cout<<status<<endl;
            }
        }
    }
    cout<<"请输入取消的记录，0代表返回：";

    while(true){
        cin>>select;
        if(select >= 0 && select <= vec.size()){
            if(select == 0){
                break;
            }
            r->m_orderData[vec[select - 1]]["status"] = "0";
            r->updateOrder();
            cout<<"已取消预约"<<endl;
            break;
        }
        cout<<"输入有误，请重新输入！"<<endl;
    }
    system("pause");
    system("cls");
    delete r;
}

