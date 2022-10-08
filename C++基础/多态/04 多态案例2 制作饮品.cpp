
#include<iostream>
using namespace std;

class AbstractDrinking{
public:

    //��ˮ
    virtual void Boil() = 0;

    //����
    virtual void Brew() = 0;

    //���뱭��
    virtual void PourInCup() = 0;

    //���븨��
    virtual void PutSomthing() = 0;

    //������Ʒ
    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomthing();
    }
};

//��������
class Coffee: public AbstractDrinking{
public:
    //��ˮ
    virtual void Boil(){
        cout<<"��ũ��ɽȪ"<<endl;
    }

    //����
    virtual void Brew(){
        cout<<"���ݿ���"<<endl;
    }

    //���뱭��
    virtual void PourInCup(){
        cout<<"���뱭��"<<endl;
    }

    //���븨��
    virtual void PutSomthing(){
        cout<<"�����Ǻ�ţ��"<<endl;
    }

};

//������ˮ
class Tea: public AbstractDrinking{
public:
    //��ˮ
    virtual void Boil(){
        cout<<"��ˮ"<<endl;
    }

    //����
    virtual void Brew(){
        cout<<"���ݲ�Ҷ"<<endl;
    }

    //���뱭��
    virtual void PourInCup(){
        cout<<"���뱭��"<<endl;
    }

    //���븨��
    virtual void PutSomthing(){
        cout<<"�����Ǻ�ţ��"<<endl;
    }

};

//��������
void dowork(AbstractDrinking * abs){
    abs->makeDrink();
    delete abs; //�ͷ�
    cout<<"==========================="<<endl;
}

void test01(){
    //��������
    dowork(new Coffee);

    //������Ҷ
    dowork(new Tea);
}

int main(){
    test01();
    return 0;
}
