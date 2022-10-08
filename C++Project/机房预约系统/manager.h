#pragma once
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <vector>
#include<iostream>
using namespace std;

//管理员类设计
class manager : public Identity{
public:

    //默认构造
    manager();

    //有参构造
    manager(string name, string pwd);

    //菜单构造
    virtual void operMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void cleanFile();

    //初始化容器
    void initVector();

    //检测重复id 检测学号、职工号 参数2，类型（学生或者教师）
    bool checkRepeat(int id, int type);

    vector<student> vStu;
    vector<teacher> vTea;
    vector<computerRoom> vCom;

};
