#include <iostream>
#include <string>
using namespace std;
//利用具体化的模板，可以解决自定义类型的通用化
//学习模板并不是为了写模板，而是在STL能够运用系统系统的模板
class Person
{

    public:
    Person(string name,int age)
    {
       this->m_Name=name;
       this->m_Age=age;
    }

    int m_Age;
    string m_Name;
};
template <class T>
bool myCompare(T &a,T &b)
{  
     if(a==b)
     {
        return true;
     }
     else{
        return false;
     }

}
//利用具体化Person的版本来实现代码，具体优化优先调用
template <>bool myCompare(Person &p1,Person &p2)
{
    if(p1.m_Name==p2.m_Name&&p1.m_Age==p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;

    }
}
void test1()
{
    int a=10;
    int b=20;
    bool ret=myCompare(a,b);
    if(ret)
    {
        cout<<"相等"<<endl;

    }
    else
    {
        cout<<"不相等"<<endl;
    }

}
void test2()
{
   Person P1("Tom",10);
   Person P2("Tom",10);
   bool ret1=myCompare(P1,P2);
   if(ret1)
    {
        cout<<"相等"<<endl;

    }
    else
    {
        cout<<"不相等"<<endl;
    }

}
int main()
{
     //test1();
     test2();
     return 0;
}