#include<string>
#include<iostream>
#include<fstream>
using namespace std;

void test01(){
    //1、创建流对象
    ifstream ifs;
    //2、打开文件，判断是否打开成功
    ifs.open("test.txt", ios::in);
    if(!ifs.is_open()){
        cout<<"文件打开失败！"<<endl;
        return ;
    }
    //3、读数据
//    第一种
//    char buf[1024] = {0};
//    while(ifs>>buf){
//        cout<<buf<<endl;
//    }
//      第二种
//    char buf[1024] = {0};
//    while(ifs.getline(buf, sizeof(buf))){
//        cout<<buf<<endl;
//    }
//    cout<<buf<<endl;
    //第三种
    string buf;
    while(getline(ifs, buf)){
        cout<<buf<<endl;
    }
//    //第四种  不推荐
//    char c;
//    while( (c = ifs.get() ) != EOF ){ //EOF end of file
//        cout<<c;
//    }
    //4、关闭文件
    ifs.close();
}

int main(){
    test01();
    return 0;
}
