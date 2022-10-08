#pragma once
#include<iostream>
#include "worker.h"
using namespace std;

class Manager: public Worker{
public:
    //构造函数
    Manager(int id, string name, int dId);

    //显示个人信息
    void showInfo();

    //获取岗位信息
    string getDeptName();
};
