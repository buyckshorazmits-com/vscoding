#include "iostream"
using namespace std;
class Base 
{
public:
  //纯虚函数
  //类中只要有一个纯虚函数就被称为抽象类
  //抽象类无法实例化对象
  //子类必须重写父类的纯虚函数 否则也属于抽象类
   virtual void func()=0;
   virtual ~Base(){}  //虚析构：delete 基类指针时，才能正确调用子类的析构函数
};
class Son:public Base
{
public:
  virtual void func()
  {
    cout<<"func的调用"<<endl;

  }

};
void test1()
{
    Base *base=NULL;

    base=new Son;//如果不重定义虚函数，Son也属于抽象类，也无法实例化对象
    base->func();
    delete base;
}
int main()
{
    test1();
   return 0;


}