#include "iostream"
using namespace std;
class Base
{
 public:
 int m_A;

 protected:
 int m_B;

 private:
 int m_c;



};
class Son:public Base
{
    public:
    int m_D;

    

};
void test1()
{
    //父类中所有的非静态成员属性都会被子类继承
    //父类中的私有成员属性 是被编译器给隐藏了，因此访问不到，但是确实被继承下去
    cout<<"sizeof="<<sizeof(Son)<<endl;
}
int main()
{

test1();
return 0;
}