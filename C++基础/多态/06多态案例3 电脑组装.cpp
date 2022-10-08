#include<iostream>
using namespace std;

class CPU{

public:
    virtual void calaulate() = 0;
};

class VideoCard{

public:
    virtual void display() = 0;
};

class Memory{

public:
    //����Ĵ洢����
    virtual void storage() = 0;
};

//������
class Computer{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    //�ṩ��������
    void work(){
        m_cpu->calaulate();

        m_vc->display();

        m_mem->storage();
    }
    virtual~Computer(){
        if(m_cpu != NULL){
            delete m_cpu;
            m_cpu = NULL;
        }
        if(m_vc != NULL){
            delete m_vc;
            m_vc = NULL;
        }
        if(m_mem != NULL){
            delete m_mem;
            m_mem = NULL;
        }
    }
private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

//���峧��
class IntelCPU: public CPU{
public:
    virtual void calaulate(){
        cout<<"Intel ��CPU�Ŀ�ʼ�����ˣ�"<<endl;
    }
};

class IntelVideoCard: public VideoCard{
public:
    virtual void display(){
        cout<<"Intel ���Կ���ʼ��ʾ�ˣ�"<<endl;
    }
};

class IntelMemory: public Memory{
public:
    virtual void storage(){
        cout<<"Intel ���ڴ濪ʼ�洢�ˣ�"<<endl;
    }
};

class LenovoCPU: public CPU{
public:
    virtual void calaulate(){
        cout<<"Lenovo ��CPU�Ŀ�ʼ�����ˣ�"<<endl;
    }
};

class LenovoVideoCard: public VideoCard{
public:
    virtual void display(){
        cout<<"Lenovo ���Կ���ʼ��ʾ�ˣ�"<<endl;
    }
};

class LenovoMemory: public Memory{
public:
    virtual void storage(){
        cout<<"Lenovo ���ڴ濪ʼ�洢�ˣ�"<<endl;
    }
};

void test01(){
    //��һ̨�������
    CPU *intelCpu = new IntelCPU;
    VideoCard *intelCard = new IntelVideoCard;
    Memory *intelMem = new IntelMemory;

    //������һ̨����
    Computer *computer1 = new Computer(intelCpu, intelCard, intelMem);
    computer1->work();
    delete computer1;

    cout<<"================================"<<endl;

    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

    cout<<"================================"<<endl;

    Computer *computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
    computer3->work();
    delete computer3;
}

int main(){
    test01();
    return 0;
}
