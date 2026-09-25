#include "iostream"
using namespace std;

//函数模板
//两个整型交换
void intswap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
//两个浮点型交换
void doubleswap(double &a,double &b)
{
    double swap=a;
    a=b;
    b=swap;
}
//函数模板
//声明一个模板，告诉编译器后面的代码中紧跟着的T不要报错，T是一个通用数据类型
template <typename T>
void MySwap(T &a, T &b)
{
    T temp =a;
    a=b;
    b=temp;
}
void test1()
{
    int a=10;
    int b=20;
    MySwap(a,b);
    cout<<"a="<<a<<" "<<"b="<<b<<endl;

    double c=11.1;
    double d=22.2;
    MySwap(c,d);                            //MySwap(c, d);  隐式推导：编译器看实参类型，自己猜出 T = double                                        
                                            //MySwap<double>(c, d); 显式指定：你直接告诉编译器 T = double，
    cout<<"c="<<c<<" "<<"d="<<d<<endl;      
}
int main()
{
  test1();
  
  return 0;

}
