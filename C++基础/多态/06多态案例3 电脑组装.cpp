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
    //抽象的存储函数
    virtual void storage() = 0;
};

//电脑类
class Computer{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *mem){
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    //提供工作函数
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

//具体厂商
class IntelCPU: public CPU{
public:
    virtual void calaulate(){
        cout<<"Intel 的CPU的开始计算了！"<<endl;
    }
};

class IntelVideoCard: public VideoCard{
public:
    virtual void display(){
        cout<<"Intel 的显卡开始显示了！"<<endl;
    }
};

class IntelMemory: public Memory{
public:
    virtual void storage(){
        cout<<"Intel 的内存开始存储了！"<<endl;
    }
};

class LenovoCPU: public CPU{
public:
    virtual void calaulate(){
        cout<<"Lenovo 的CPU的开始计算了！"<<endl;
    }
};

class LenovoVideoCard: public VideoCard{
public:
    virtual void display(){
        cout<<"Lenovo 的显卡开始显示了！"<<endl;
    }
};

class LenovoMemory: public Memory{
public:
    virtual void storage(){
        cout<<"Lenovo 的内存开始存储了！"<<endl;
    }
};

void test01(){
    //第一台电脑零件
    CPU *intelCpu = new IntelCPU;
    VideoCard *intelCard = new IntelVideoCard;
    Memory *intelMem = new IntelMemory;

    //创建第一台电脑
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
