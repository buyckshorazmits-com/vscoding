#include "iostream"
using namespace std;
//访问权限
//三种
//公共权限public  成员  类内可以访问  类外可以访问
//保护权限protected   成员  类内可以访问  类外不可以访问  儿子可以访问父亲中的保护内容
//私有权限private  成员  类内可以访问  类外不可以访问     儿子不可以访问父亲的私有内容
//struct 的默认权限是公共    class的默认权限是私有的
class Person
{
  public:
  //公共权限
  string m_name;

  protected :
  //保护权限
  string m_car;
  private:
  //私有权限
  int m_password;

public ://如果换成private 在main()中就不能访问 func()函数  相当于是私有权限内容，类外访问不到
   void func()
  {
    m_name="张三";
    m_car="拖拉机";   //函数体内部是类内环境
    m_password=123456;
  }

};
int main()
{
//实例化对象
 Person p1;
 //p1.m_car="奔驰"；保护权限内容，在类外访问不到
 //p1.m_password=123;  私有权限内容，类外访问不到
 p1.m_name="李四";



}
