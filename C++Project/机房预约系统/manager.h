#pragma once
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
#include <vector>
#include<iostream>
using namespace std;

//����Ա�����
class manager : public Identity{
public:

    //Ĭ�Ϲ���
    manager();

    //�вι���
    manager(string name, string pwd);

    //�˵�����
    virtual void operMenu();

    //����˺�
    void addPerson();

    //�鿴�˺�
    void showPerson();

    //�鿴������Ϣ
    void showComputer();

    //���ԤԼ��¼
    void cleanFile();

    //��ʼ������
    void initVector();

    //����ظ�id ���ѧ�š�ְ���� ����2�����ͣ�ѧ�����߽�ʦ��
    bool checkRepeat(int id, int type);

    vector<student> vStu;
    vector<teacher> vTea;
    vector<computerRoom> vCom;

};
