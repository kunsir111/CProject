#include "workerManager.h"
#include "employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager(){

}

void WorkerManager::ShowMenu(){
    cout << "\t\t\t\t*******************************************"<< endl;
    cout << "\t\t\t\t********** ��ӭʹ��ְ������ϵͳ! **********"<< endl;
    cout << "\t\t\t\t=============: 0.�˳�������� ============="<< endl;
    cout << "\t\t\t\t=============: 1.����ְ����Ϣ ============="<< endl;
    cout << "\t\t\t\t=============: 2.��ʾְ����Ϣ ============="<< endl;
    cout << "\t\t\t\t=============: 3.ɾ����ְְ�� ============="<< endl;
    cout << "\t\t\t\t=============: 4.�޸�ְ����Ϣ ============="<< endl;
    cout << "\t\t\t\t=============: 5.����ְ����Ϣ ============="<< endl;
    cout << "\t\t\t\t=============: 6.���ձ������ ============="<< endl;
    cout << "\t\t\t\t=============: 7.��������ĵ� ============="<< endl;
    cout << "\t\t\t\t==========================================="<< endl;
    cout << endl;
}

void WorkerManager::ExitSystem(){
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");

    exit(0);

}

void WorkerManager::Add_Emp(){
    cout<<"��������ӵ�Ա��������"<<endl;
    int addNum = 0;  //�����û�������
    cin>>addNum;
    if(addNum > 0){
         for(int i = 0; i < addNum; i += 1){
            int id;
            string name;
            int dId;

            cout<<"������� "<<(i + 1)<<" ����Ա���ı�ţ�"<<endl;
            cin>>id;
            cout<<"������� "<<(i + 1)<<" ����Ա����������"<<endl;
            cin>>name;
            cout<<"��ѡ���ְ����λ"<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ϰ�"<<endl;
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
            //��������ְ�����浽

            if(worker != NULL){
                delete worker;
                worker = NULL;
            }
         }
    } else {
        cout<<"������������"<<endl;
    }
}

WorkerManager::~WorkerManager(){

}
