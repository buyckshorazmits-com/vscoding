#include "iostream"
using namespace std;
class Buildding
{

//告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容
friend void goodGay(Buildding *buildding);
  public:
  Buildding()
  {
    this->m_SittingRoom="客厅";
    this->m_BedRoom="卧室";
  }
public:
string  m_SittingRoom;

private:
string m_BedRoom;
};
void goodGay(Buildding *buildding)//全局函数作为友元
{
cout<<"好友正在访问："<<buildding->m_SittingRoom<<endl;
cout<<"好友正在访问："<<buildding->m_BedRoom<<endl;


}
int main()
{
Buildding buildding;
goodGay(&buildding);
return 0;
}