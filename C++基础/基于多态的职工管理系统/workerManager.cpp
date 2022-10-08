#include "workerManager.h"
#include "employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager(){

}

void WorkerManager::ShowMenu(){
    cout << "\t\t\t\t*******************************************"<< endl;
    cout << "\t\t\t\t********** 欢迎使用职工管理系统! **********"<< endl;
    cout << "\t\t\t\t=============: 0.退出管理程序 ============="<< endl;
    cout << "\t\t\t\t=============: 1.增加职工信息 ============="<< endl;
    cout << "\t\t\t\t=============: 2.显示职工信息 ============="<< endl;
    cout << "\t\t\t\t=============: 3.删除离职职工 ============="<< endl;
    cout << "\t\t\t\t=============: 4.修改职工信息 ============="<< endl;
    cout << "\t\t\t\t=============: 5.查找职工信息 ============="<< endl;
    cout << "\t\t\t\t=============: 6.按照编号排序 ============="<< endl;
    cout << "\t\t\t\t=============: 7.清空所有文档 ============="<< endl;
    cout << "\t\t\t\t==========================================="<< endl;
    cout << endl;
}

void WorkerManager::ExitSystem(){
    cout<<"欢迎下次使用"<<endl;
    system("pause");

    exit(0);

}

void WorkerManager::Add_Emp(){
    cout<<"请输入添加的员工数量："<<endl;
    int addNum = 0;  //保存用户的数量
    cin>>addNum;
    if(addNum > 0){
         for(int i = 0; i < addNum; i += 1){
            int id;
            string name;
            int dId;

            cout<<"请输入第 "<<(i + 1)<<" 个新员工的编号："<<endl;
            cin>>id;
            cout<<"请输入第 "<<(i + 1)<<" 个新员工的姓名："<<endl;
            cin>>name;
            cout<<"请选择该职工岗位"<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cin>>dId;
            Worker *worker = NULL;
            switch(dId){
                case 1:
                    worker = new Employee(id, name, dId);
                    break;
                case 2:
                    worker = new Manager(id, name, dId);
                    break;
                case 3:
                    worker = new Boss(id, name, dId);
                    break;
            }
            //将创建的职工保存到

            if(worker != NULL){
                delete worker;
                worker = NULL;
            }
         }
    } else {
        cout<<"输入数据有误"<<endl;
    }
}

WorkerManager::~WorkerManager(){

}
