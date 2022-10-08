
#pragma once
#include<vector>
#include "computerRoom.h"
#include<iostream>
using namespace std;
#include "Identity.h"

class student : public Identity{
public:
    //默认构造
    student();

    //有参构造
    student(int id, string name, string pwd);

    //菜单界面
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看自身预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int m_Id;

    vector<computerRoom> vCom;
};
