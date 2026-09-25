#include "iostream"
using namespace std;

class Base1
{
    public:
    Base1()
    {
        m_A=100;

    }
   public:
   int m_A;

};
class Base2
{
   public:
   Base2()
   {
    
    m_A=200;
   }
   public:
   int m_A;

};
//语法：class 子类：继承方式 父类1 ，继承方式 父类2
class Son:public Base2,public Base1
{
 public:
 Son()
 {
    m_C=300;
    m_D=400;
 }
 public:
 int m_C;
 int m_D;
};
//多继承容易产生成员同名的情况
//通过使用类名作用域可以区分调用哪一个基类的成员
void test1()
{
 Son s;
 cout<<"sizeof Son="<<sizeof(s)<<endl;
 cout<<s.Base1::m_A<<endl;//如果直接s.m_A会报错，编译器不知道访问哪个基类的m_A  所以必须注明作用域
 cout<<s.Base2::m_A<<endl;


}
int main()
{
  test1();
  return 0;
}