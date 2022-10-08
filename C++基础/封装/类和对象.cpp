#include<iostream>
#include<cmath>
using namespace std;


const double PI = acos(-1);

class Circle{
    //访问权限
public:
    //属性
    //半径
    double m_r;


    double circleParmeter(){
        return 2 * PI * m_r;
    }
};

int main(){
    Circle c1;
    c1.m_r = 10;
    cout<<c1.circleParmeter();
}
