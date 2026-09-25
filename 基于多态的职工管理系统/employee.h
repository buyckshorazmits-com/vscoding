#pragma once//防止头文件重复包含
#include "iostream"
#include  "string"
#include "woker.h"
using namespace std;

class Employee: public Worker
{
  public:
  //构造函数
  Employee(int id,string name ,int did);
  //显示个人信息
  virtual void showinfo();
  //获取岗位名称
  virtual string getDeptName();
   
};
