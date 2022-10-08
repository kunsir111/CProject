
#include<iostream>
using namespace std;

//继承实现页面

class BasePage{
public:
    void header(){
        cout <<"首页、公开课、登录、注册...(公共头部)"<< endl;
    }
    void footer(){
        cout <<"帮助中心、交流合作、站内地图...(公共底部)"<< endl;
    }
    void left(){
        cout << "Java、Python、C++、...(公共分类列表)"<< endl;
    }
};

//继承的好处：减少重复的代码
//语法： class 子类名: 继承方式 父类名{
//
//}
//子类也称为派生类
//父类也称为基类

//Java页面
class Java :public BasePage{

public:
    void content(){
        cout<<"Java学科视频"<<endl;
    }

};
//Python页面
class Python :public BasePage{

public:
    void content(){
        cout<<"Python学科视频"<<endl;
    }

};
//C++页面
class CPP :public BasePage{

public:
    void content(){
        cout<<"C++学科视频"<<endl;
    }

};

void test01(){
    Java java;
    java.header();
    java.footer();
    java.left();
    java.content();
    cout<<"===================================="<<endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout<<"===================================="<<endl;
    CPP cp;
    cp.header();
    cp.footer();
    cp.left();
    cp.content();
    cout<<"===================================="<<endl;
}

int main(){
    test01();
    return 0;
}
