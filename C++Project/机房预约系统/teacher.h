#pragma once
#include<iostream>
using namespace std;

#include "Identity.h"

//��ʦ�����
class teacher:public Identity{
public:

    //Ĭ�Ϲ���
    teacher();

    //�вι���
    teacher(int empId, string name, string pwd);

    //����˵�
    virtual void operMenu();

    //�鿴����ԤԼ
    void showAllOrder();

    //���ԤԼ
    void validOrder();

    //ְ����
    int m_EmpId;
};
