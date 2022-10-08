#pragma once
#include<iostream>
using namespace std;

#include "Identity.h"

//教师类设计
class teacher:public Identity{
public:

    //默认构造
    teacher();

    //有参构造
    teacher(int empId, string name, string pwd);

    //界面菜单
    virtual void operMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    //职工号
    int m_EmpId;
};
