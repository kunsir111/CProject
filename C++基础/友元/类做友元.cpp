
#include<iostream>
using namespace std;

//������Ԫ

class Building;

class GoodGay{
public:
    GoodGay();
    void visit();//�ιۺ�������Building�е�����
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


//����д��Ա����
Building::Building(){
    m_SittingRoom = "����";
    m_BedRoom = "����";
}

void GoodGay::visit(){
    cout<<"�û��������ڷ��ʣ�"<<building->m_SittingRoom<<endl;
    cout<<"�û��������ڷ��ʣ�"<<building->m_BedRoom<<endl;
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
