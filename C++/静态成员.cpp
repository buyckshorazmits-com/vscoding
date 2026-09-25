#include "iostream"
using namespace std;
class Person 
{

    //所有对象都共享同一份数据
    //编译阶段就分配内存
    //类内声明 类外初始化操作
public:

static int m_A;

};
int Person::m_A=100;//类内声明 类外初始化操作
void test1()
{
  Person p;
  p.m_A=100;
  cout<<p.m_A<<endl;

  Person p1;
  p1.m_A=200;
  cout<<p.m_A<<endl;//p和p1共享一份数据
  cout<<p1.m_A<<endl;

}
void test2()
{
   //静态变量

}
int  main()
{
 test1();

}