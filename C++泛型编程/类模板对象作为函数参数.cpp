#include<iostream>
#include "string"
using namespace std;
template <class T1,class T2>
//用类模板对象作为函数参数
class Person
{
    public:
    Person(T1 name,T2 age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }

    string m_Name;
    int m_Age;
    void showPerson ()
    {
        cout<<"name="<<this->m_Name<<"age="<<this->m_Age<<endl;
    }
};
//指定传入类型 
void PrintPerson1(Person<string,int >&p)
{
    p.showPerson();
}
void test1()
{
    Person <string ,int >p1("张三",18);
    p1.showPerson();

}
//参数模板化
template<class T1,class T2>
void printPerson2(Person <T1,T2>&p)
{
  p.showPerson();
  cout <<"T1的数据类型为："<<typeid(T1).name()<<endl;
  cout<<"T2的数据类型为:"<<typeid (T2).name()<<endl;
}
void test2()
{
    Person <string ,int >p3("赵武",19);
    printPerson2(p3);
}
int main()
{
  //test1();
 // Person p2("李四",10);
  //p2.showPerson();
  return 0;

}