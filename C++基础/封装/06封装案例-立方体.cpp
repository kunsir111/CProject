
#include<iostream>
using namespace std;


//�����������
//1��������������
//2���������
//3�������Ϊ ��ȡ��������������
//4���ֱ�����ȫ�ֺ����ͳ�Ա����  �ж������������Ƿ����

class Cube{

private:
    int m_L;
    int m_H;
    int m_W;
public:
     //���ó�
     void setL(int l){
        m_L = l;
     }
     //��ȡ��
     int getL(){
        return m_L;
     }
     //���ÿ�
     void setW(int w){
        m_W = w;
     }
     //��ȡ��
     int getW(){
        return m_W;
     }
     //���ø�
     void setH(int h){
        m_H = h;
     }
     //��ȡ��
     int getH(){
        return m_H;
     }
     //��ȡ����������
    int getArea(){
        return 2 * m_L * m_W + 2 * m_L * m_H + 2 * m_W * m_H;
    }
    //��ȡ���������
    int getVolum(){
        return m_L * m_H * m_W;
    }
    bool isSameByClass(Cube &c){
        if(m_L == c.getL() && m_H == c.getH() && m_W == c.getW()){
            return true;
        }
        return false;
    }
};

//����ȫ�ֺ����жϳ������Ƿ����
bool isSame(Cube &c1, Cube &c2){
    if(c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW()){
        return true;
    }
    return false;
}

int main(){
    Cube c1;
    c1.setL(10);
    c1.setH(10);
    c1.setW(10);
    cout<<"c1�ı������"<<c1.getArea()<<endl;
    cout<<"c1���������"<<c1.getVolum()<<endl;

    Cube c2;
    c2.setL(10);
    c2.setH(10);
    c2.setW(10);

    bool ret = isSame(c1, c2);
    if(ret){
        cout<<"c1��c2���"<<endl;
    }else {
        cout<<"c1��c2�����"<<endl;
    }

    bool ret1 = c1.isSameByClass(c2);
    if(ret1){
        cout<<"��Ա�����жϣ�c1��c2���"<<endl;
    }else {
        cout<<"��Ա�����жϣ�c1��c2�����"<<endl;
    }
    return 0;
}
