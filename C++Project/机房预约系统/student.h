
#pragma once
#include<vector>
#include "computerRoom.h"
#include<iostream>
using namespace std;
#include "Identity.h"

class student : public Identity{
public:
    //Ĭ�Ϲ���
    student();

    //�вι���
    student(int id, string name, string pwd);

    //�˵�����
    virtual void operMenu();

    //����ԤԼ
    void applyOrder();

    //�鿴����ԤԼ
    void showMyOrder();

    //�鿴����ԤԼ
    void showAllOrder();

    //ȡ��ԤԼ
    void cancelOrder();

    //ѧ��ѧ��
    int m_Id;

    vector<computerRoom> vCom;
};
