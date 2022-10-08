
#include<iostream>
using namespace std;


//立方体类设计
//1、创建立方体类
//2、设计属性
//3、设计行为 获取立方体面积和体积
//4、分别利用全局函数和成员函数  判断两个立方体是否相等

class Cube{

private:
    int m_L;
    int m_H;
    int m_W;
public:
     //设置长
     void setL(int l){
        m_L = l;
     }
     //获取长
     int getL(){
        return m_L;
     }
     //设置宽
     void setW(int w){
        m_W = w;
     }
     //获取宽
     int getW(){
        return m_W;
     }
     //设置高
     void setH(int h){
        m_H = h;
     }
     //获取高
     int getH(){
        return m_H;
     }
     //获取长方体表面积
    int getArea(){
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
    }
    //获取长方体体积
    int getVolum(){
        return m_L * m_H * m_W;
    }
    bool isSameByClass(Cube &c){
        if(m_L == c.getL() && m_H == c.getH() && m_W == c.getW()){
            return true;
        }
        return false;
    }
};

//利用全局函数判断长方体是否相等
bool isSame(Cube &c1, Cube &c2){
    if(c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW()){
        return true;
    }
    return false;
}

int main(){
    Cube c1;
    c1.setL(10);
    c1.setH(10);
    c1.setW(10);
    cout<<"c1的表面积："<<c1.getArea()<<endl;
    cout<<"c1的体积积："<<c1.getVolum()<<endl;

    Cube c2;
    c2.setL(10);
    c2.setH(10);
    c2.setW(10);

    bool ret = isSame(c1, c2);
    if(ret){
        cout<<"c1和c2相等"<<endl;
    }else {
        cout<<"c1和c2不相等"<<endl;
    }

    bool ret1 = c1.isSameByClass(c2);
    if(ret1){
        cout<<"成员函数判断，c1和c2相等"<<endl;
    }else {
        cout<<"成员函数判断，c1和c2不相等"<<endl;
    }
    return 0;
}
