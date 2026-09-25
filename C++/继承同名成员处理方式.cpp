#include"iostream"
using namespace std;
#include "string"


class Base
{
   public:
   Base()
   {
     m_A=100;

   }
void func()
{
  cout<<"Base--func()的调用"<<endl;
}
void func(int a)
{
    cout<<"Base--func(int a)的调用"<<endl;
}

public:
   int m_A;

};
class Son:public Base{
public: 
   Son()
   {
    m_A=200;
   }
   //当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
	//如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
   void func()
   {
    cout<<"Son--func()的调用"<<endl;
   }

   public:
   int m_A;
};
void test1()
{
    Son s;
  cout<<"Son下的m_A="<<s.m_A<<endl;
  cout<<"Base下的m_A="<<s.Base::m_A<<endl;

  s.func();//默认调用s本身的成员函数  因为当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
  s.Base::func();//注明了s从继承的Base中调用成员函数
  s.Base::func(10);
  
}
int main()
{
  test1();
  return EXIT_SUCCESS;

}