#include<iostream>

using namespace std;

//动物类
class Animal{
public:
    int m_Age;
};

//利用虚继承 解决菱形继承的问题
//继承之前 加上关键字 virtual
//羊类
class Sheep: virtual public Animal{

};


//驼类
class Camel: virtual public Animal{

};

//羊驼类
class SheepCamel: public Sheep, public Camel{

};

void test01(){
    SheepCamel sc;
    sc.Sheep::m_Age = 18;
    sc.Camel::m_Age = 20;
    cout<<"sc.Sheep::m_Age = "<<sc.Sheep::m_Age<<endl;
    cout<<"sc.Camel::m_Age = "<<sc.Camel::m_Age<<endl;
    cout<<"sc.m_Age =  "<<sc.m_Age<<endl;
}

int main(){

    test01();
    return 0;
}
