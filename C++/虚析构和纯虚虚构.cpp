#include "iostream"
using namespace std;

class Animal
{
    public:
    Animal()  //构造函数
    {
        cout<<"Animal 构造函数调用"<<endl;
    }
    virtual void speak()=0; 
//析构函数加上virtual关键字，变成虚析构函数
	//virtual ~Animal()
	//{
	//	cout << "Animal虚析构函数调用！" << endl;
	//}

    //纯虚析构函数
    virtual~ Animal()=0;
};
//虚析构和纯虚析构共性：

//1.可以解决父类指针释放子类对象
//2.都需要有具体的函数实现，不能光是一个声明。虚析构virtual ~类名(){}；括号里得有东西；纯虚析构virtual ~类名() = 0;`得在类外定义
//纯虚析构virtual ~类名() = 0;得在类外定义
Animal::~Animal()
{

    cout<<"Animal的析构函数的调用"<<endl;

}
//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
class Cat:public Animal
{
public:
Cat(string name)
{
   cout<<"Cat构造函数调用"<<endl;
   m_Name=new string (name);
}
virtual void speak()
{
        cout<<*m_Name<<"小猫在说话"<<endl;
}
~Cat()
{
    cout<<"Cat析构函数的调用"<<endl;
  if(m_Name!=NULL)
  {
   delete  m_Name;
   m_Name=NULL;
  }
 

}

public:
string *m_Name;
};
void test1()
{
    //多态（虚函数）使用条件：父类指针或引用指向子类对象
    Animal *animal=new Cat("Tom");//构造函数先父后子：
    animal->speak();
    delete animal;//因为 Animal 的析构是虚的（纯虚析构也是虚的），所以 delete 时析构函数的调用先子后父（和构造顺序正好相反）
}
int main()
{
test1();
return 0;
}