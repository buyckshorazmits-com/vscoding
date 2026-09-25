#include "iostream"
using namespace std;
//函数重载需要函数在同一个作用域下
void func()
{
  cout<<"func 的调用"<<endl;
}
void func(int a)
{
    cout<<"func(int a)的调用"<<endl;
}
void func(double a)
{
    cout<<"func(double a)的调用"<<endl;
}
void func(int a,double b)
{
    cout<<"func(int a,double b)的调用"<<endl;
}
void func(double a,int b)
{
    cout<<"func(double a,int b)的调用"<<endl;
}

//函数返回值不能作为函数重载条件
// int func(double a,int b)
//{
//  cout<<"func(double a,int b)的调用"<<endl;
//}

void func1(int &a)
{
 cout<<"func1(int &a)的调用"<<endl;//引用作为重载条件

}
void func1 (const int &a)
{
    cout<<"func1(const int &a)的调用"<<endl;
}
void func2(int a,int b=10)
{
    cout<<"func2(int a,int b=10)的调用"<<endl;//函数重载碰到函数默认参数
}
void func2(int a)
{

    cout<<" func2(int a)的调用"<<endl;
}
int main()
{
int a=10;
 func();
 func(10);
 func(3.14);//编译出来的警告主要是因为传入函数的值没有使用
 func(10,3.14);
 func(3.14,10);
 func1(a);//调用无const
 func1(100);//调用有const

//func2(10); 碰到默认参数会产生歧义，要避免

 return 0;


}
//