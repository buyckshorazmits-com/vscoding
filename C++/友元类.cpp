#include"iostream"
#include "string"
using namespace std;
class Buildding;
class goodGay{

    public:
    goodGay();
    void visit();

    private:
    Buildding *building;


};
class Buildding
{
    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
    friend class goodGay;
    public:
    Buildding();

    public:
    string m_SittingRoom;

    private:
    string m_BedRoom;

  
};
goodGay::goodGay()
{
  //创建一个建筑物的对象
  building=new Buildding;//在堆区创建一个对象

}
void goodGay::visit()
{
  cout<<"好友类正在访问："<<building->m_SittingRoom<<endl;
  cout<<"好友类正在访问："<<building->m_BedRoom<<endl;
}
//类内声明后，类外定义构造函数需要加类作用域
Buildding::Buildding()
{
    this->m_SittingRoom="客厅";
    this->m_BedRoom="卧室";
}
void test1()
{
  goodGay gg;
  gg.visit();

}

int main()
{
test1();
return 0;

}