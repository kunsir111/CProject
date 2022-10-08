
#include<iostream>
using namespace std;

class Calculator{

public:
    int getResult(string oper){
        if(oper == "+"){
            return m_Num1 + m_Num2;
        } else if(oper == "-"){
            return m_Num1 - m_Num2;
        } else if(oper == "*"){
            return m_Num1 * m_Num2;
        }

    }
    int m_Num1; //操作数1
    int m_Num2; //操作数2
};

void test01(){
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 10;
    cout<<c.m_Num1<<" + "<<c.m_Num2<<" = "<<c.getResult("+")<<endl;
    cout<<c.m_Num1<<" - "<<c.m_Num2<<" = "<<c.getResult("-")<<endl;
    cout<<c.m_Num1<<" * "<<c.m_Num2<<" = "<<c.getResult("*")<<endl;
}

//利用多态实现计算器
//实现计算器抽象类

class AbstractCalculator{
public:
    virtual int getResult(){
        return 0;
    }
    int m_Num1;
    int m_Num2;
};

//加法计算器类
class AddCalculator: public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 + m_Num2;
    }
};

class SubCalculator: public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 - m_Num2;
    }
};

class MulCalculator: public AbstractCalculator{
public:
    int getResult(){
        return m_Num1 * m_Num2;
    }
};

void test02(){
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout<<abc->m_Num1 <<" + " << abc->m_Num2<<" = "<<abc->getResult()<<endl;
    //用完后记得销毁
    delete abc;

    abc = new SubCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout<<abc->m_Num1 <<" - " << abc->m_Num2<<" = "<<abc->getResult()<<endl;
    //用完后记得销毁
    delete abc;

    abc = new MulCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout<<abc->m_Num1 <<" * " << abc->m_Num2<<" = "<<abc->getResult()<<endl;
    //用完后记得销毁
    delete abc;
}

int main(){

//    test01();
    test02();
    return 0;
}
