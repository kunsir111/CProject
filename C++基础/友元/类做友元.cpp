
#include<iostream>
using namespace std;

//类做友元

class Building;

class GoodGay{
public:
    GoodGay();
    void visit();//参观函数访问Building中的属性
    Building *building;

};

class Building{
    friend class GoodGay;
public:
    Building();

public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};


//类外写成员函数
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

void GoodGay::visit(){
    cout<<"好基友类正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好基友类正在访问："<<building->m_BedRoom<<endl;
}

void test01(){
    GoodGay gg;
    gg.visit();
}

GoodGay::GoodGay(){
     building = new Building;
}

int main(){
    test01();
    return 0;
}
