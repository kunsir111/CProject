#include "boss.h"

Boss::Boss(int id, string name, int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DepId = dId;
}

void Boss::showInfo(){
    cout<<"老板编号："<<this->m_Id<<"\t老板姓名："<<this->m_Name<<"\t岗位："<<this->getDeptName()
    <<"\t岗位职责：管理公司所有事物"<<endl;
}

string Boss::getDeptName(){
    return "老板";
}
