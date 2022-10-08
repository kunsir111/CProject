
#include<iostream>
using namespace std;

class Person{

public:
    void  showCLassName(){
        cout<<"this is Person class"<<endl;
    }
    void showPersonAge(){
        if(this == NULL){
            return;
        }
        cout<<"age = "<<m_Age<<endl;
    }
    int m_Age;
};

void test01(){
    Person *p = NULL;
    p->showCLassName();
    p->showPersonAge();
}

int main(){
    test01();
    return 0;
}
