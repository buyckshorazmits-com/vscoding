#include<iostream>
#include<set>
#include<string>
using namespace std;

class Person
{
    public:
    Person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }

    string m_name;
    int m_age;
};

class MyCompare
{
    public:
    bool operator()(const Person &p1,const Person &p2) const
    {
        return p1.m_age>p2.m_age;
    }
        //()符号重载   防止两个同龄不同名的人造成重复
};
void test1()
{
    //set的模板参数内置了升序排列规则  这里改变规则就得自己定义
    set<Person,MyCompare> s1;//把排序规则换成 MyCompare
    Person p1("s1",11);
    Person p2("s2",22);
    Person p3("s3",33);
    Person p4("s4",44);

    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);

    for(set<Person,MyCompare>::iterator it=s1.begin();it !=s1.end();it++)
    {
        cout<<it->m_name<<" "<<it->m_age<<endl;
    }
}
int main(void)
{
    test1();
    system("pause");
    return 0;
}
//利用仿函数可以指定set容器的排序规则。
//对于自定义数据类型，set必须指定排序规则才可以插入数据。