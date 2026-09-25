#include "iostream"
using namespace std;
//发现是引用，转换为int* ref=&a;
void func(int &ref)
{
   ref  =100;//ref是引用，转换为*ref=100;

}
void showValue(const int&v)
{
   cout<<v<<endl;

}
int main()
{
   int a=10;
   //自动转换为int* const ref =&a,指针常量指向是不能更改的，也说明为什么引用不可更改
   int & ref=a;
   ref=20;//内部发现ref是引用，自动帮我们转换为：*ref =20;
   cout<<"a="<<a<<endl;
   cout<<"ref:"<<ref<<endl;
   func(a);
   return 0;


   //int&b_ref =20;引用本身需要一个合法的空间，因此这行错误
   //加入const修饰就可以，编译器优化代码，int temp=20;const int &b_ref=temp;
  const int& b_ref=20;
  cout<<b_ref <<endl;

  //如果b_ref=100;加入const 后不可修改变量
  int b=30;
  //函数中利用常量引用防止误操作修改实参
  showValue(b);
  return 0;
}