
#include<iostream>
using namespace std;

class Building{
    //告诉编译器goodGay全局函数是 Building类的好朋友，可以访问类中的私有内容
    friend void goodGay(Building *building);
public:
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";

    }
public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};

void goodGay(Building *building){
    cout<<"好基友的全局函数 正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好基友的全局函数 正在访问："<<building->m_BedRoom<<endl;
}
void test01(){
    Building building;
    goodGay(&building);

}

int main(){
    test01();
    return 0;
}
