#include"iostream"
#include "string"
using namespace std;
class Person1
{
  public:
  void showperson1()
  {
    cout<<"Person show1"<<endl;
  }

};
class Person2
{
    public:
    void showperson2()
    {
        cout<<"Person show2"<<endl;
    }

};

template <class T>
class Myclass
{
    public:
    T Obj;
    void fun1()
    {
        Obj.showperson1();
    }
    void fun2()
    {
        Obj.showperson2();
    }
};
void test1()
{
    Myclass<Person2> p;//模板用 Person2 替换 T,生成一个全新的类
    //p.fun1();
    p.fun2();
}


int main()
{
    test1();
    return 0;
}  