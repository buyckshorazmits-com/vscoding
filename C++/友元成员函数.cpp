#include "iostream"
#include "string"
using namespace std;
class Buildding;
class GoodGay
{
  public:
  GoodGay();

  void visit();
  void visit1();
Buildding *building;

};
class Buildding
{
friend void GoodGay::visit1();//告诉GoodGay类下的visit成员函数作为本类的好朋友，可以访问Buildding 类下的私有成员变量
public:

Buildding ();

public :
string m_sittingRoom;

private:
string m_BedRoom;

};
Buildding::Buildding ()
{
  m_sittingRoom="客厅";
  m_BedRoom="卧室";
  

}
void GoodGay::visit()
{ 
  cout<<"好友正在访问客厅："<<building->m_sittingRoom<<endl;

}
void GoodGay::visit1()
{
    
    cout<<"好友正在访问卧室："<<building->m_BedRoom<<endl;
}
GoodGay::GoodGay()
{


  building=new    Buildding;

}
void test()
{
    GoodGay gg;
    gg.visit();
    gg.visit1();
}
int main()
{
test();
return 0;
}