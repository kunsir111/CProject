#pragma once //防止头文件包含
#include<iostream>
using namespace std;
class WorkerManager{

public:

    //构造函数
    WorkerManager();

    //展示菜单
    void ShowMenu();


    //添加职工
    void Add_Emp();

    //退出系统
    void ExitSystem();

    //析构函数
    ~WorkerManager();

};
