#include<iostream>

using namespace std;
class Building;
class GoodGay{
public:
    GoodGay();

    void visit();//让visit函数可以访问Building中私有成员
    void visit2();//让visit2函数不可以访问Building中私有成员
public:
    Building *building;
};

class Building{
    friend void GoodGay::visit();
    friend void GoodGay::visit2();
public:
    Building();

public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay(){

    building = new Building;

}

void GoodGay::visit(){
    cout<<"visit函数正在访问："<<building->m_SittingRoom<<endl;
    cout<<"visit函数正在访问："<<building->m_BedRoom<<endl;
}

void GoodGay::visit2(){
    cout<<"visit函数正在访问："<<building->m_SittingRoom<<endl;
    cout<<"visit函数正在访问："<<building->m_BedRoom<<endl;
}

void test01(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main(){
    test01();
    return 0;
}
