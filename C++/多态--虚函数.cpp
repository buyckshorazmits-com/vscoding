#include "iostream"
using namespace std;

class Animal
{
public:
 virtual void speak()
{
    //函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
    //不加virtual，sizeof(Animal)=1，即空类占用内存为1（只有非静态成员变量占用类/类的对象的内存空间）
	//加上virtual后，sizeof(Animal)=4，出现一个虚函数指针vfptr;
    //此处定义虚函数必须有virtual
  cout<<"动物在说话"<<endl;
}
};
class Cat:public Animal
{
    public:

    void speak()
    {
      cout<<"小猫在说话"<<endl;
    }
};
class Dog:public Animal
{
    public:
    void speak()
    {
        cout<<"小狗在乱叫"<<endl;

    }
};
void DoSpeak(Animal &animal)
{
    animal.speak();
}
void test1()
{
    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
}
int main()
{
  test1();
  return 0;
}