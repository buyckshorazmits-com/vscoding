#include "iostream"
using namespace std;
//加号运算符重载
class Person 
{
  public:
  // 成员函数重载+号（与全局函数版本二选一，不能同时存在）
  //Person operator+(Person &p)
  //{
  //  Person temp;
  //  temp.m_A=this->m_A+p.m_A;
  //  temp.m_B=this->m_B+p.m_B;
  //  return temp;
  //}

  int m_A=10;
  int m_B=10;

};
// 比如想让 int + Person 也生效
//Person operator+(int num, Person &p) {
  //  Person temp;
   // temp.m_A = num + p.m_A;
    //temp.m_B = num + p.m_B;
    //return temp;
//}

// 使用
//Person p1;
//Person p3 = 5 + p1;   // ✅ 全局函数可以，成员函数做不到
// 全局函数重载+号                
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.m_A=p1.m_A+p2.m_A;
    temp.m_B=p1.m_B+p2.m_B;
    return temp;
}
void test1()
{
  Person p1;
  p1.m_A=10;
  p1.m_B=10;

 Person p2;
  p2.m_A=10;
  p2.m_B=10;

  Person p3=p2+p1;
  cout<<"p3.m_A="<<p3.m_A<<endl;
  cout<<"p3.m_B="<<p3.m_B<<endl;
}
int main()
{

test1();
return 0;
}