#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;
class Person
{
   public:
   Person(string name,int age,int height)
   {
    this->m_name=name;
    this->m_age=age;
    this->m_height=height;
   }
   string m_name;
   int m_age;
   int m_height;

};
//指定排序规则
bool myCompare(Person &p1,Person &p2)
{//按年龄升序

  if(p1.m_age==p2.m_age)
  {
    //年龄相同 则按身高降序
    return p1.m_height>p2.m_height;
  }
  else
  {
   return p1.m_age<p2.m_age;
  }
}

void test1()
{
    list<Person> L1;
    Person p1("s11",23,165);
    Person p2("s12",23,170);
    Person p3("s13",23,173);
    Person p4("s14",21,180);
    Person p5("s15",32,165);
    Person p6("s16",28,175);

    L1.push_back(p1);
    L1.push_back(p2);
    L1.push_back(p3);
    L1.push_back(p4);
    L1.push_back(p5);
    L1.push_back(p6);
    
    cout<<"排序前："<<endl;
    for(list<Person>::iterator it=L1.begin();it !=L1.end();it++)
    {
      cout<<it->m_name<<" "<<it->m_age<<" "<<it->m_height<<endl;
    }
     cout<<"排序后："<<endl;
    //排序后
    L1.sort(myCompare);
    for(list<Person>::iterator it=L1.begin();it!=L1.end();it++)
    {
        cout<<it->m_name<<" "<<it->m_age<<" "<<it->m_height<<endl;
    }
}
int main()
{
    test1();
    system("pause");
    return 0;
}
