
#pragma once
#include<iostream>
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>
using namespace std;


class orderFile{
public:
    //构造函数
    orderFile();

    //更新
    void updateOrder();

    //记录预约条数
    int m_Size;

    //key 记录条数
    map<int, map<string, string> > m_orderData;
};
