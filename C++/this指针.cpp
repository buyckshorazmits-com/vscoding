#include "iostream"
using namespace std;

class Person 
{
  public :
  Person (int age)
  {
  //1、当形参和成员变量同名时，可用this指针来区分；
		//如果不加this,最后会输出乱码，即编译器认为成员变量age和Person构造函数里的3个age（形参+构造函数体内的age=age）不是一个东西
    this->age=age;//this指针指向被调用的成员函数 的所属对象
  }
//加了引用&表示PersonAddPerson返回的对象和p2占用同一个内存,最后输出40
//如果不加&，则编译器调用默认拷贝构造函数，进行值返回，然而返回的新对象已经和原来的p2不占同一个内存空间，也就是说下面程序链式调用了3次，最后生成了3个不同的新对象.
//不加&，最后输出20.既然生成3个新对象，为什么输出不是原来的P2，反而还加成功了一次呢？其实，过程是：调用默认拷贝构造函数，this->age += p.age;已经this指针仍然是指向p2,return *this返回一个新的对象
  Person &PersonAddPerson(Person p)
  {
    this->age+=p.age;
 
     return *this;//返回对象本身

  }

int age;

};
void test1()
{
  Person p1(10);
  cout<<"p1.age="<<p1.age<<endl;

  Person p2(10);
  //链式编程思想（cout利用<<一直输出也是这种思想）
  p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
  cout<<"p2.age="<<p2.age<<endl;


}
int main()
{
  test1();

  return 0;


}