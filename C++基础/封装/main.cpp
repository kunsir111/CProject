#include<iostream>
#include "point.h"
#include "circle.h"
using namespace std;


//class Point{
//
//private:
//    int m_X;
//    int m_Y;
//
//public:
//    void setX(int x){
//        m_X = x;
//    }
//    int getX(){
//        return m_X;
//    }
//    void setY(int y){
//        m_Y = y;
//    }
//    int getY(){
//        return m_Y;
//    }
//};


//class Circle{
//
//private:
//    int m_R;
//    Point m_Center;
//
//public:
//    void setR(int r){
//        m_R = r;
//    }
//    int getR(){
//        return m_R;
//    }
//    void setCenter(Point center){
//        m_Center = center;
//    }
//    Point getCenter(){
//        return m_Center;
//    }
//};

void isInCircle(Circle &c, Point &p){
    //计算两点之间的距离 平方
    int dis = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    //
    int r = c.getR() * c.getR();

    if(dis == r){
        cout<<"点在圆上"<<endl;
    } else if(dis > r){
        cout<<"点在圆外"<<endl;
    }else{
        cout<<"点在圆内"<<endl;
    }
}

int main(){

    //创建圆
    Circle c;
    Point p;
    p.setX(10);
    p.setY(0);
    c.setR(10);
    c.setCenter(p);
    //创建点
    Point p1;
    p1.setX(10);
    p1.setY(11);
    isInCircle(c, p1);
    return 0;
}
