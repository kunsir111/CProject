
#pragma once
#include<iostream>
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>
using namespace std;


class orderFile{
public:
    //���캯��
    orderFile();

    //����
    void updateOrder();

    //��¼ԤԼ����
    int m_Size;

    //key ��¼����
    map<int, map<string, string> > m_orderData;
};
