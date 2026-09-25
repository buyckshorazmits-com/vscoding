#include "iostream"
using namespace std;



class Person 
{
public :

Person(int age)
{
    m_Age= new int (age);

}
//重载赋值运算符 
//返回值加引用，是为了可以链式编程，实现连等操作a=b=c
Person& operator=(Person *p)
{
    //由于对象在定义时，上述构造函数会自动在堆区分布内存，需要先清空
  if(m_Age!=NULL)
  {
    delete m_Age;
    m_Age=NULL;
  }
  //编译器提供的代码是浅拷贝，虽然调用后会正常输出值，但在程序结束调用析构函数时会发生内存重复释放，导致程序崩掉.
		//m_Age = p.m_Age;
  m_Age=new int (*p->m_Age);//提供深拷贝 解决浅拷贝的问题
  return *this;//返回自身

}
~Person()
{
 if(m_Age!=NULL)
 {
   delete m_Age;
    m_Age=NULL;

 }

}
int *m_Age;

};
void test1()
{
  Person p1(10);
  Person p2(20);
  Person p3(30);
  p3=p2=p1;
  cout<<"p1的年龄为："<<*p1.m_Age<<endl;
  cout<<"p2的年龄为："<<*p2.m_Age<<endl;
  cout<<"p3的年龄为："<<*p3.m_Age<<endl;
}
int main()
{
test1();
return 0;
}