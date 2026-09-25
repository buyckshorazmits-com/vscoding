#include<iostream>
#include<queue>
#include<string>
using namespace std;
//Queue是一种先进先出的数据结构，它有两个出口
//只有队头和队尾能被外界访问，因此不允许有遍历行为。

//队列容器允许从一端新增元素，从另一端移除元素。

//队列中进入数据——入队。

//队列中出数据——出队。
class Person
{
    public:
    Person(string name,int age)
    {
     this->M_name=name;
     this->M_age=age;
    }
    string M_name;
    int M_age;
};
void test1()
{ 
  
    queue<Person> p;
    Person p1("s1",12);
    Person p2("s2",14);
    Person p3("s3",16);
    Person p4("s4",18);

    p.push(p1);
    p.push(p2);
    p.push(p3);
    p.push(p4);

    cout<<"大小："<<p.size()<<endl;

    while(!p.empty())
    {
        cout<<p.front().M_name<<" "<<p.front().M_age<<endl;
        p.pop();

    }
    cout<<"大小："<<p.size()<<endl;
}
int main()
{
    test1();
    system("pause");
    return 0;
}