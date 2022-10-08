#include "orderFile.h"
#include "globalFile.h"
#include <map>
#include <utility>
#include <string>

void split(string s, map<string, string > & m){
    string key;
    string value;
    int pos = s.find(":");
    key = s.substr(0, pos);
    value = s.substr(pos + 1, s.size() - (pos + 1));
    m.insert(make_pair(key, value));
//    cout<<"key: " << key<<endl;
//    cout<<"value: " << value<<endl;
}

orderFile::orderFile(){
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    string data;    //日期
    string interval;//时间段
    string stuId;   //学生学号
    string stuName; //学生姓名
    string roomId;  //机房编号
    string status;  //预约状态
    this->m_Size = 0; //记录条数

    while(ifs >> data && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status){
//        cout<<data<<endl;
//        cout<<interval<<endl;
//        cout<<stuId<<endl;
//        cout<<stuName<<endl;
//        cout<<roomId<<endl;
//        cout<<status<<endl;
        map<string, string> m;
        split(data, m);
        split(interval, m);
        split(stuId, m);
        split(stuName, m);
        split(roomId, m);
        split(status, m);
        this->m_orderData.insert(make_pair(this->m_Size, m));
        this->m_Size++;
    }
    ifs.close();

//    for(map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++){
//        cout<<"key: "<<it->first<<"value: "<<endl;
//
//        for(map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++){
//            cout<<mit->first<<" "<<mit->second<<endl;
//        }
//    }

}

    //更新
void orderFile::updateOrder(){
    if(this->m_Size == 0){
        cout<<"无预约记录！"<<endl;
        system("pause");
        system("cls");
        return ;
    }
    ofstream ofs(ORDER_FILE, ios::out|ios::trunc);
    for(int i = 0; i < this->m_Size; i++){
        ofs<<"date:"<<this->m_orderData[i]["date"]<<" ";
        ofs<<"interval:"<<this->m_orderData[i]["interval"]<<" ";
        ofs<<"stuId:"<<this->m_orderData[i]["stuId"]<<" ";
        ofs<<"stuName:"<<this->m_orderData[i]["stuName"]<<" ";
        ofs<<"roomId:"<<this->m_orderData[i]["roomId"]<<" ";
        ofs<<"status:"<<this->m_orderData[i]["status"]<<endl;
    }
    ofs.close();
}
