#include "iostream"
using namespace std;

//常函数


class Person 
{
    //this指针的本质是指针常量，指针的指向是不可以修改的
public:
 Person() {
		m_A = 0;
		m_B = 0;
	}
    //const Person*const this:
    //在成员函数后面加const ,修饰的是this指向，让指针指向的值也不可更改
    void showPerson()const
    {
        //this->m_A=100;
        //this=NULL;//this指针不可以修改指针的指向
        this->m_B=100;
    }
    void myfuc()
    {

    }
public:
int m_A;
mutable int m_B;//特殊变量  加关键字mutable 即使在常函数中，也可以修改这个值，

};
void test1()
{
   Person p;
  p.showPerson();
   
 // this->m_B;//在成员函数内部可以使用   test1()是外部函数 非成员函数


}
//常对象
void test2()
{
 const Person p1;
 p1.m_B=100; 
 //p1.m_A=1000;//常对象是不能修改成员变量的值  可以访问
 cout<<p1.m_B<<endl;

 //p1.myfuc();//常对象不能调用  非const的函数
}
int main()
{
test1();
 test2();
 return 0;
}