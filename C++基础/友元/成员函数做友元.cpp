#include<iostream>

using namespace std;
class Building;
class GoodGay{
public:
    GoodGay();

    void visit();//��visit�������Է���Building��˽�г�Ա
    void visit2();//��visit2���������Է���Building��˽�г�Ա
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
    m_SittingRoom = "����";
    m_BedRoom = "����";
}

GoodGay::GoodGay(){

    building = new Building;

}

void GoodGay::visit(){
    cout<<"visit�������ڷ��ʣ�"<<building->m_SittingRoom<<endl;
    cout<<"visit�������ڷ��ʣ�"<<building->m_BedRoom<<endl;
}

void GoodGay::visit2(){
    cout<<"visit�������ڷ��ʣ�"<<building->m_SittingRoom<<endl;
    cout<<"visit�������ڷ��ʣ�"<<building->m_BedRoom<<endl;
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
