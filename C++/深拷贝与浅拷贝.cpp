#include "iostream"
using namespace std;

class Person{
 public:
 Person()
 {
  cout<<"Person的默认构造函数"<<endl;

 }
Person(int age,int hight)
{
    m_Age=age;
    m_Hight=new int (hight);
    cout<<"Person的有参构造函数调用"<<endl;


}
Person (const Person &p)
{
    cout<<"Person 拷贝构造函数调用"<<endl;
    m_Age=p.m_Age;
 //m_Hight=p.m_Hight; 编译器默认实现
 //深拷贝操作
    m_Hight=new int (*p.m_Hight); //利用*p.m_Hight解引用的值作  在堆区再申请一个空间
}
~Person()
{
     //析构代码，将堆区开辟数据做释放操作
     if(m_Hight!=NULL)
     {
        delete m_Hight;
        m_Hight=NULL;
     }
    cout<<"Person的析构函数调用"<<endl;
}

int m_Age;
int *m_Hight;
};
void test1()
{
    Person p1(18,160);
    cout<<"p1的年龄为："<<p1.m_Age<<"身高："<<*p1.m_Hight<<endl;
    Person p2(p1);
    cout<<"p2的年龄为："<<p2.m_Age<<"身高："<<*p1.m_Hight<<endl;
}
int main()
{
    test1();
}