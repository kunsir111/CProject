 #include<iostream>
using namespace std;

//访问权限
//三种
//公共权限 public        成员  类内可以访问，类外可以访问
//保护权限 protected     成员  类内可以访问，类外不可以访问 儿子可以访问父亲的内容
//私有权限 private       成员  类内可以访问，类外不可以访问 儿子不可以访问父亲的内容

class Person{

public:
    //公共权限
    string m_Name;
protected:
    string m_Car;

private:
    int m_Password;

public:
    void func(){
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
    void printInfo(){
        cout<<m_Name<<" "<<m_Car<<" "<<m_Password<<endl;
    }
};

int main(){
    Person p1;
    p1.func();
    p1.printInfo();
    return 0;
}
