
#include<iostream>
using namespace std;

class AbstractDrinking{
public:

    //煮水
    virtual void Boil() = 0;

    //冲泡
    virtual void Brew() = 0;

    //倒入杯中
    virtual void PourInCup() = 0;

    //加入辅料
    virtual void PutSomthing() = 0;

    //制作饮品
    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomthing();
    }
};

//制作咖啡
class Coffee: public AbstractDrinking{
public:
    //煮水
    virtual void Boil(){
        cout<<"煮农夫山泉"<<endl;
    }

    //冲泡
    virtual void Brew(){
        cout<<"冲泡咖啡"<<endl;
    }

    //倒入杯中
    virtual void PourInCup(){
        cout<<"倒入杯中"<<endl;
    }

    //加入辅料
    virtual void PutSomthing(){
        cout<<"加入糖和牛奶"<<endl;
    }

};

//制作茶水
class Tea: public AbstractDrinking{
public:
    //煮水
    virtual void Boil(){
        cout<<"煮水"<<endl;
    }

    //冲泡
    virtual void Brew(){
        cout<<"冲泡茶叶"<<endl;
    }

    //倒入杯中
    virtual void PourInCup(){
        cout<<"倒入杯中"<<endl;
    }

    //加入辅料
    virtual void PutSomthing(){
        cout<<"加入糖和牛奶"<<endl;
    }

};

//制作函数
void dowork(AbstractDrinking * abs){
    abs->makeDrink();
    delete abs; //释放
    cout<<"==========================="<<endl;
}

void test01(){
    //制作咖啡
    dowork(new Coffee);

    //制作茶叶
    dowork(new Tea);
}

int main(){
    test01();
    return 0;
}
