
#include<iostream>
using namespace std;

//虚析构和纯虚析构
//1.虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
//2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
//3.拥有纯虚析构函数的类也属于抽象类
class Animal{
public:
    Animal(){
        cout<<"Animal 构造函数调用"<<endl;
    }
//    //利用虚析构可以解决 父指针释放子类对象时不干净的问题
//    virtual ~Animal(){
//        cout<<"Animal 虚析构函数调用"<<endl;
//    }
    //纯虚析构
    virtual ~Animal() = 0;

    //纯虚函数
    virtual void speak() = 0;
};

Animal::~Animal(){
    cout<<"Animal 纯虚 析构函数调用"<<endl;
}

class Cat: public Animal{
public:
    Cat(string name){
        cout<<"Cat 构造函数调用"<<endl;
        m_Name = new string(name);
    }
    ~Cat(){
        if(m_Name != NULL){
            cout<<"Cat 析构函数调用"<<endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    virtual void speak(){
        cout<<*m_Name<<"小猫在说话"<<endl;
    }
    string *m_Name;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal;
}

int main(){

    test01();
    return 0;
}

