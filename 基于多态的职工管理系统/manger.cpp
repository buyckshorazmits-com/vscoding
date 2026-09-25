#include "manger.h"
#include "woker.h"
using namespace std;

Manger::Manger(int id,string name ,int did)
{
   this->m_Id=id;
   this->m_Name=name;
   this->m_DeptId=did;
}
void Manger::showinfo()
{
  cout<<"职工编号:"<<this->m_Id
      <<"\t职工姓名:"<<this->m_Name
      <<"\t岗位编号:"<<this->getDeptName()
      <<"\t岗位职责:完成boss的任务"<<endl;


}
string Manger::getDeptName()
{
  return string("经理");
}