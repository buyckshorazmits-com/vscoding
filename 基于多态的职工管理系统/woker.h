#pragma once//防止头文件重复包含
#include "iostream"
#include  "string"
using namespace std;

//职工抽象类
class Worker
{
public:
//显示个人信息
virtual void showinfo()=0;
//获取岗位名称
virtual string getDeptName()=0;
//虚析构函数：保证通过基类指针 delete 派生类对象时正确析构
virtual ~Worker(){}
  //职工编号
  int m_Id;
  //职工姓名
  string m_Name;
  //岗位编号
  int  m_DeptId;
};