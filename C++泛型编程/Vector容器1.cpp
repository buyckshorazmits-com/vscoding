#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//vector中存放自定义数据类型
class Person
{
    public:
    Person(string name,int age)
    {
      this->m_age=age;
      this->m_Name=name;
    }

    string m_Name;
    int   m_age;
};
void test1()
{
    vector <Person> v;
    Person p1("a1",10);
    Person p2("a2",20);
    Person p3("a3",30);
    Person p4("a4",40);
    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
   //遍历容器中的数据
   for(vector <Person> ::iterator it=v.begin();it!=v.end();it++)
   {
      cout<<"姓名："<< it->m_Name<< "年龄：" <<it->m_age<< endl;
   }
}
//存放自定义数据类型
void test2()
{
  vector <Person *> v;
  Person p1("a1",12);
  Person p2("a2",13);
  Person p3("a3",14);
  Person p4("a4",15);
  Person p5("a5",16);

  v.push_back(&p1);
  v.push_back(&p2);
  v.push_back(&p3);
  v.push_back(&p4);
  v.push_back(&p5);

  for(vector<Person *>:: iterator it=v.begin();it !=v.end();it++ )
  {
    cout<<"姓名："<<(* it)->m_Name<<"年龄："<<(*it)->m_age<<endl;
  }
}

int main()
{ 
    test1();
    test2();
    system("pause");
    return 0;
}

