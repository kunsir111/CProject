#pragma once
#include<iostream>
#include "point.h"
using namespace std;
class Circle{

private:
    int m_R;
    Point m_Center;

public:
    void setR(int r);
    int getR();
    void setCenter(Point center);
    Point getCenter();
};
