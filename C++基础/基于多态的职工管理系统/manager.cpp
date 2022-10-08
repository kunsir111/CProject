#include "manager.h"

Manager::Manager(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = dId;
}

void Manager::showInfo(){
    cout<<"经理编号："<<this->m_Id<<"\t经理姓名："<<this->m_Name<<"\t岗位："<<this->getDeptName()
    <<"\t岗位职责：处理老板交给的任务，并交给员工"<<endl;
}

string Manager::getDeptName(){
    return "经理";
}
