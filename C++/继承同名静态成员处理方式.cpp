#include "iostream"
using namespace std;
class Base
{
  public:
  static void func()
  {
    cout<<"Base-static void func()"<<endl;
    //静态成员函数重载
   
  }
 static void func(int a)
    {
       cout<<"Base--static void func(int a)"<<endl;

    }
    static int m_A;


};
//静态成员变量类内声明，类外初始化
int Base::m_A=100;
class Son:public Base
{
  public:
  static void func()
  {
    cout<<"Son--static void func()"<<endl;

  }
static int m_A;

};
int Son::m_A=200;
void test1()
{
    //通过对象访问
    cout<<"通过对象访问："<<endl;
    Son s;
    cout<<"Son 下m_A="<<s.m_A<<endl;
    cout<<"Base下m_A="<<s.Base::m_A<<endl;

    //通过类名访问
    cout<<"//通过类名访问"<<endl;
    cout<<"Son 下m_A="<<Son::m_A<<endl;
    cout<<"Base下m_A="<<Son::Base::m_A<<endl;
    //也可以通过Base类名直接访问 cout << "Base 下 m_A = " <<Base::m_A << endl;
	//Son::Base::m_A中Son::表示通过Son类名访问，Base::指定访问作用域
}
//同名成员函数
void test2()
{
 //通过对象访问
  cout<<"通过对象访问："<<endl;
  Son s;
  s.func();
  s.Base::func();

 //通过类名访问
 cout<<"通过类名访问："<<endl;
 Son::func();
 Son::Base::func();
 //出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
 Son::Base::func(10);
 //Son::func(100);//访问的仍然是Son中的函数func

}
int main()
{
//test1();
test2();
return 0;
}