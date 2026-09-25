#include "iostream"
using namespace std;

// ============================================================
// 多态案例：组装电脑
// ------------------------------------------------------------
// 核心思路：父类指针指向子类对象 + 虚函数 => 运行时多态
//  ① 抽象基类（CPU / VideoCard / Memory）：只规定"该干什么"
//  ② 具体子类（Inter / Lenovo 两个品牌）：实现"各自怎么干"
//  ③ Computer 类：把零件装起来，统一调度（不关心具体品牌）
//  ④ 换不同的零件（子类对象），work() 行为随之改变，代码不用改
// ============================================================

class CPU
{
   public:
   // 纯虚函数（=0）：规定"CPU 必须能计算"，具体怎么算由子类决定
   // 有纯虚函数的类 = 抽象类，不能实例化，只能被继承
    virtual void calculate()=0;

    // 虚析构函数：通过基类指针 delete 子类对象时，
    // 会先调用子类析构，再调用父类析构，避免未定义行为
    virtual ~CPU(){}
   
};
class VideoCard
{
   public:
   // 纯虚函数：规定"显卡必须能显示"
    virtual void display()=0;

    // 虚析构函数：原因同上
    virtual ~VideoCard(){}
   
};
class Memory
{
   public:
   // 纯虚函数：规定"内存必须能存储"
    virtual void storage()=0;

    // 虚析构函数：原因同上
    virtual ~Memory(){}
   
};
class  Computer
{
    public:
    // 构造函数：收下三个零件（指针），存进成员变量
    // 形参 cpu/vc/mem 是传入的地址，m_cpu/m_vc/m_mem 是成员变量
    Computer(CPU *cpu,VideoCard *vc,Memory *mem)
    {
        m_cpu=cpu;
        m_vc=vc;
        m_mem=mem;
    }
     // 提供工作函数：指挥三个零件干活
    // m_cpu 是父类指针，调用虚函数 calculate()
    // 实际执行的是"传入的子类"的版本 => 多态的体现
    void work()
    {
         m_cpu->calculate();// 这里就是多态的"触发点"

         m_vc->display();

         m_mem->storage();
    }

    // 析构函数：电脑销毁时，把三个零件一起 delete 释放，防止内存泄漏
    // 每次 delete 后把指针置 NULL，避免"悬空指针"（野指针）
    ~Computer()
    {
        if(m_cpu!=NULL)
        {
            delete m_cpu;
            m_cpu=NULL;
        }
        if(m_vc!=NULL)
        {
            delete m_vc;
            m_vc=NULL;
        }
         if(m_mem!=NULL)
        {
            delete m_mem;
            m_mem=NULL;
        }
    }
   

    private:
    CPU *m_cpu;// 注意：成员是父类指针
    VideoCard *m_vc;
    Memory *m_mem;
};
class InterCPU:public CPU
{
    public:
    // 重写父类的纯虚函数 calculate()，实现 Intel 版本
    virtual void calculate()
    {
      cout<<"Inter的cpu开始计算了"<<endl;
    }
};
class InterVideoCard:public VideoCard
{
    public:
    // 重写 display()，实现 Intel 显卡版本
    virtual void display()
    {
      cout<<"Inter的显卡开始显示了"<<endl;
    }
};
class InterMemory:public Memory
{
    public:
    // 重写 storage()，实现 Intel 内存版本
    virtual void storage()
    {
      cout<<"Inter的存储开始了"<<endl;
    }
};
class LenovoCPU:public CPU
{
    public:
    // 重写 calculate()，实现联想 CPU 版本
    virtual void calculate()
    {
      cout<<"Lenovo的cpu开始计算了"<<endl;
    }
};
class LenovoVideoCard:public VideoCard
{
    public:
    // 重写 display()，实现联想显卡版本
    virtual void display()
    {
      cout<<"Lenovo的显卡开始显示了"<<endl;
    }
};
class LenovoMemory:public Memory
{
    public:
    // 重写 storage()，实现联想内存版本
    virtual void storage()
    {
      cout<<"Lenovo的存储开始了"<<endl;
    }
};
void test1()
{
    //组装第一台电脑（全 Intel 配置）
    cout<<"第一台开始工作"<<endl;
    // 先用 new 在堆上创建零件，地址存进变量
    // 注意：左侧是父类指针（CPU *），右侧 new 的是子类（InterCPU）
    //       => 父类指针指向子类对象，是多态的前提
    CPU *interCpu=new InterCPU;
    VideoCard*interCard=new InterVideoCard;
    Memory*interMem=new InterMemory;
    
    // 把三个零件的地址传进 Computer 构造函数（装电脑）
    Computer*computer1=new Computer(interCpu,interCard,interMem);
    computer1->work();   // work 里通过虚函数触发多态，输出 Iner 三行
    delete computer1;    // 销毁电脑，析构函数会连带释放三个零件
    cout<<"-------------"<<endl;
    cout<<"第二台开始工作"<<endl;
    // 全联想配置：直接在参数里 new，不经过中间变量，更简洁
    Computer*computer2=new Computer(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
    computer2->work();   // 输出 Lenovo 三行
    delete computer2;

    cout<<"-------------"<<endl;
    cout<<"第三台开始工作"<<endl;
    // 混搭配置：联想 CPU + Intel 显卡 + Intel 内存
    // Computer 只认父类指针，所以任何子类组合都合法
     Computer*computer3=new Computer(new LenovoCPU,new InterVideoCard,new InterMemory);
    computer3->work();   // 输出：Lenovo 的 CPU + Iner 的显卡/内存
    delete computer3;

}
int main()
{
    // 程序入口：调用组装测试函数
    test1();
    return 0;   // 返回 0 表示程序正常结束
            
}